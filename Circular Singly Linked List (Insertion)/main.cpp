#include <iostream>

using namespace std;
// here we will maintain a last pointer rather than a first pointer
// Since, Last pointer has a link to first pointer. So, it is wise to have a link to last pointer

struct node
{
    int data;
    node * next;
};
node* insertAtBegining(node * last,int data)
{
    if(last==NULL)
    {
        last = new node();
        last->data=data;
        last->next=last;
        return last;
    }
    node * temp=new node();
    temp->data=data;
    temp->next=last->next;
    last->next=temp;
    return last;
}
node * append(node * last,int data)
{
    if(last==NULL)
    {
        last=new node();
        last->data=data;
        last->next=last;
        return last;
    }
    node *temp = new node();
    temp->data=data;
    temp->next=last->next;
    last->next=temp;
    return temp;
}
node*  insertAfter(node* last,int data,int newNodeData)
{
    if(last==NULL)
    {
        cout<<"CLL is empty\n";
        return last;
    }
    node * originalLast = last;
    while(last->data != data)
    {
        last=last->next;
        if(last==originalLast)
            break;
    }
    if(last->data==data)
    {
        node *temp= new node();
        temp->data= newNodeData;
        temp->next= last->next;
        last->next=temp;
        if(last==originalLast)
            return last->next;  // insertion at the last , so last is changed
    }
    else
    {
        cout<<"Element with data:"<<data<<" is not found\n";
    }
    return originalLast;
}
void printCLL(node * last)
{
    if(last==NULL)
    {
        cout<<"CLL is empty\n";
        return;
    }
    node * OriginalLast=last;
    last=last->next;
    while(last!=OriginalLast)
    {
        cout<<last->data;
        cout<<" -> ";
        last=last->next;
    }
    cout<<OriginalLast->data<<"\n";
}

int main()
{
    node * last=NULL; // CLL is Empty
    last = append(last,1);
    last = append(last,2);
    last = append(last,3);
    last = insertAtBegining(last,0);
    printCLL(last);
    last = insertAfter(last,3,1);
    printCLL(last);

    last = insertAfter(last,5,1);  // No element
    printCLL(last);
    return 0;
}

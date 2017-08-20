#include <iostream>

using namespace std;
struct node
{
    int data;
    node * next;
};
node * append(node *last,int data)
{
    if(last==NULL)
    {
        last=new node();
        last->data=data;
        last->next=last;
        return last;
    }
    node * temp = new node();
    temp->data= data;
    temp->next=last->next;
    last->next=temp;
    return temp;
}
void printCLL(node * last)
{
    if(last==NULL)
    {
        cout<<"CLL is empty\n";
        return;
    }
    node* originalLast = last;
    last=last->next;
    while(last!=originalLast)
    {
        cout<<last->data<<"->";
        last=last->next;
    }
    cout<<originalLast->data<<"\n";
}
node * sortedInsert(node *last,int data)
{
    if(last==NULL)
    {
        return append(last,3);
    }
    if(last->data <= data)  // insertion at end
    {
        node *temp = new node();
        temp->data =data;
        temp->next=last->next;
        last->next=temp;
        return temp;
    }
    node *originalLast = last;
    while(last->next!=originalLast)
    {
        if(last->next->data >=data)
            break;
        last=last->next;
    }
    node *temp = new node();
    temp->data =data;
    temp->next=last->next;
    last->next = temp;
    return originalLast;
}
int main()
{
    node * last  = NULL;
    last = append(last,1);
    last = append(last,5);
    last = append(last,6);
    last = append(last,7);
    last = append(last,7);
    printCLL(last);
    last =sortedInsert(last,3);
    printCLL(last);
    return 0;
}

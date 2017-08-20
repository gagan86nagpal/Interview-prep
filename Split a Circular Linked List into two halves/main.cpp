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

node * split(node * last)
{
    node* originalLast =last;
    if(last==NULL)
    {
        cout<<"CLL is empty\n";
        return last;
    }
    else if(last->next==last)
    {
        cout<<"CLL can't be split as there is only 1 node present\n";
        return last;
    }
    else
    {
        node* first=last->next;
        node * second = first->next;
        while(second!=originalLast)
        {
            first=first->next;
            second=second->next;
            if(second==originalLast)
                break;
            second=second->next;
            if(second==originalLast)
                break;
        }
        second=first->next;
        first->next=originalLast->next;
        originalLast->next=second;
        return first;
    }
}
int main()
{
    node * last1=NULL;
    last1 = append(last1,1);
    last1 = append(last1,2);
    last1 = append(last1,3);
    last1 = append(last1,4);
    last1 = append(last1,5);
    last1 = append(last1,6);
    last1 = append(last1,7);
    last1 = append(last1,8);

    printCLL(last1);
    node * last2 = split(last1);
    if(last2!=last1)
    {
        cout<<"First Half: ";
        printCLL(last2);
        cout<<"Second Half: ";
        printCLL(last1);
    }
    else
    {
        cout<<"One Half :";
        printCLL(last1);
    }

    return 0;
}

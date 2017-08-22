#include <iostream>

using namespace std;
struct node
{
    int data;
    node* next;
    node* prev;
};
node *append(node * head,int data)
{
    node * originalHead =head;
    while(head!=NULL&&head->next!=NULL)
        head=head->next;
    node* temp=new node();
    temp->data=data;
    temp->prev=head;
    if(head!=NULL)
        head->next=temp;
    temp->next=NULL;
    if(head==NULL)
        originalHead=temp;
    return originalHead;
}
void printListForward(node* head )
{
    if(head==NULL)
    {
        cout<<"List is empty\n";
        return;
    }
    while(head!=NULL)
    {
        cout<<head->data;
        if(head->next!=NULL)
            cout<<" -> ";
        head=head->next;
    }
    cout<<"\n";
}

// Partition Function
node* part(node* first,node* last)
{
    node *one,*two;
    int temp;
    one=new node();
    one->next=first;   // 1 node behind to first node
    two=first;
    while(two!=last)
    {
        if(two->data < last->data)
        {
            temp=one->next->data;
            one->next->data=two->data;
            two->data=temp;
            one=one->next;
        }
        two=two->next;
    }
    temp=one->next->data;
    one->next->data=two->data;
    two->data=temp;
    return one->next;
}

// Quick SOrt
void qsort(node* first,node * last)
{
    if(first!=last && first!=NULL &&last!=NULL)
    {
        node* p = part(first,last);
        if(p!=first)
            qsort(first,p->prev);
        if(p!=last)
            qsort(p->next,last);
    }
}


int main()
{
    node * head=NULL;
    head=append(head,1);
    head=append(head,5);
    head=append(head,1);
    head=append(head,65);
    head=append(head,12);
    head=append(head,14);
    printListForward(head);


    node * first=head;
    node *last=first;
    while(last!=NULL&&last->next!=NULL)
        last=last->next;

    qsort(first,last);

    printListForward(head);

    return 0;
}

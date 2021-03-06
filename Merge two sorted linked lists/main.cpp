#include <iostream>

using namespace std;


struct node
{
    int data;
    node* next;
};
node* insertAtBeginning(node * head,int data)
{
    node * temp = new node();
    temp->data =data;
    temp->next = head;
    head = temp;
    return head;
}
// This code is very redundant,
// A lot of improvement can be done by just maintaining loop invariant.
// Will update the improved version if possible.
node * mergeSorted(node * head1,node * head2)
{
    node * head=NULL;
    node * tail=NULL;
    if(head1==NULL && head2==NULL)
        return NULL;
    if(head1==NULL)
    {
        head = new node();
        head->next=NULL;
        head->data=head2->data;
        head2= head2->next;
        tail=head;
        while(head2!=NULL)
        {
            tail->next = new node();
            tail=tail->next;
            tail->next=NULL;
            tail->data = head2->data;
            head2=head2->next;
        }
        return head;
    }
    if(head2==NULL)
    {
        head = new node();
        head->next=NULL;
        head->data=head1->data;
        head1= head1->next;
        tail=head;
        while(head1!=NULL)
        {
            tail->next = new node();
            tail=tail->next;
            tail->next=NULL;
            tail->data = head1->data;
            head1=head1->next;
        }
        return head;
    }
    // initializing head pointer
    if(head1->data < head2->data)
    {
        head=new node();
        head->data = head1->data;
        head1=head1->next;
        tail = head;
    }
    else
    {
        head=new node();
        head->data = head2->data;
        head2=head2->next;
        tail = head;
    }

    // Basic algorithm
    while( (head1!=NULL )&& (head2!=NULL ))
    {
        if(head1->data < head2->data)
        {
            tail->next = new node();
            tail=tail->next;
            tail->next=NULL;
            tail->data = head1->data;
            head1=head1->next;
        }
        else
        {
            tail->next = new node();
            tail=tail->next;
            tail->next=NULL;
            tail->data = head2->data;
            head2=head2->next;
        }
    }
    // if second list is exhausted first
    while(head1!=NULL)
    {
        tail->next = new node();
        tail=tail->next;
        tail->next=NULL;
        tail->data = head1->data;
        head1=head1->next;
    }
    // if first list is exhausted first
    while(head2!=NULL)
    {
        tail->next = new node();
        tail=tail->next;
        tail->next=NULL;
        tail->data = head2->data;
        head2=head2->next;
    }
    return head;
}
void printList(node * head)
{
    while(head!=NULL)
    {
        cout<<head->data;
        if(head->next!=NULL)
            cout<<" -> ";
        head=head->next;
    }
    cout<<"\n";
}

int main()
{
    node * head1 = NULL;
    node * head2 = NULL;
    node * mergedList = NULL;
    head1=insertAtBeginning(head1,10);
    head1=insertAtBeginning(head1,10);
    head1=insertAtBeginning(head1,10);
    head1=insertAtBeginning(head1,0);
    printList(head1);

    head2=insertAtBeginning(head2,20);
    head2=insertAtBeginning(head2,10);
    head2=insertAtBeginning(head2,10);
    head2=insertAtBeginning(head2,14);
    head2=insertAtBeginning(head2,12);
    head2=insertAtBeginning(head2,8);
    head2=insertAtBeginning(head2,5);
    head2=insertAtBeginning(head2,2);
    printList(head2);


    mergedList  = mergeSorted(head1,head2);
    printList(mergedList);
    return 0;
}

#include <iostream>

using namespace std;


/*
if changes are made in the linked list only and does not involve movement of head pointer , then there is no need
of returning a head pointer.
But if head pointer is changed to point to a new node , then local head pointer of main() should be updated.

So, head->next will always change the underlying data structure(linked list) and we don't need to update head pointer , but when
head is updated then it's local value should also be.

This is why in append() and insertAfterNode() , we are not returning the new head pointer because we haven't changed it's location.
Actually , we changed the linked list at heap and still old pointer points to it.

But in insertBeginning() head pointer is now a brand new allocated node , and this should be updated.

*/
struct node
{
    int data;
    node* next;

};

node* insertBeginning(node* head,int data)
{
    if(head==NULL)
    {
        head=new node();
        head->data=data;
        head->next=NULL;
    }
    else
    {
        node * temp = new node();
        temp->data=data;
        temp->next=head;
        head=temp;
    }
    return head;
}
void insertAfterNode(node * head , int data)
{
    if(head==NULL)
    {
        cout<<"Node is NUll\n";
    }
    node * temp =new node();
    temp->data=data;
    temp->next=head->next;
    head->next=temp;
}
void printlist(node * head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<"\n";
}
void append(node* head ,int data)
{
    while(head->next!=NULL)
        head=head->next;
    // head is now end node
    node * temp = new node();
    temp->data = data;
    temp->next = NULL;
    head->next = temp;
}
int main()
{
    node* head  = new node();
    node* second = new node();
    node* third = new node();
    head->data=1;
    head->next=second;

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=NULL;

    printlist(head);
    head = insertBeginning(head,10);
    printlist(head);

    insertAfterNode(head,50);
    printlist(head);

    append(head,100);
    printlist(head);
    return 0;
}

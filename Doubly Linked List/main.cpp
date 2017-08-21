#include <iostream>

using namespace std;

struct node
{
    int data;
    node *prev, *next;
};
node* insertionAtFront(node *head,int data)
{
    node* temp = new node();
    temp->data=data;
    temp->next=head;
    temp->prev=NULL;
    if(head!=NULL)
        head->prev=temp;
    return temp;
}

// Forward Traversal
void printListForward(node *head)
{
    if(head==NULL)
        cout<<"List is Empty";
    while(head!=NULL)
    {
        cout<<head->data;
        if(head->next!=NULL)
            cout<<"->";
        head=head->next;
    }
    cout<<"\n";
}
// backward traversal
void printListBackward(node * head)
{
    if(head==NULL)
    {
        cout<<"List is Empty\n";
        return ;
    }
    while(head->next!=NULL)
        head=head->next;
    while(head!=NULL)
    {
        cout<<head->data;
        if(head->prev!=NULL)
            cout<<" <- ";
        head=head->prev;
    }
    cout<<"\n";
}

// insertion at the end
node* append(node * head,int data)
{
    node* originalHead = head;

    while(head!=NULL &&head->next!=NULL)
        head=head->next;
    node * temp  = new node();
    temp->data=data;
    temp->prev=head;
    if(head!=NULL)
        head->next=temp;
    temp->next=NULL;
    if(originalHead==NULL)
        originalHead=temp;
    return originalHead;
}
void insertAfterAGivenNode(node *head,int data,int newData)
{
    while(head!=NULL)
    {
        if(head->data==data)
            break;
        head=head->next;
    }
    if(head==NULL)
    {
        cout<<"Node with data:"<<data<<" not found\n";
    }
    else
    {
        node * temp = new node();
        temp->data=newData;
        temp->next=head->next;
        head->next=temp;
        temp->prev=head;
    }
}

node* insertBeforeAGivenNode(node* head,int data, int newData)
{
    node * originalHead = head;
    while(head!=NULL)
    {
        if(head->data==data)
            break;
        head=head->next;
    }
    if(head==NULL)
    {
        cout<<"Node with data:"<<data<<" not found\n";
    }
    else
    {
        node* temp =new node();
        temp->data=newData;
        temp->next=head;
        temp->prev=head->prev;
        if(head->prev!=NULL)
            head->prev->next=temp;
        head->prev=temp;

        if(temp->prev==NULL)
            originalHead=temp;
    }
    return originalHead;
}
int main()
{
    node * head=NULL;


    printListForward(head);
    printListBackward(head);

    head=append(head,1);
    head=append(head,2);
    head=append(head,3);
    head=insertionAtFront(head,0);


    printListForward(head);
    printListBackward(head);


    insertAfterAGivenNode(head,3,4);
    head=insertBeforeAGivenNode(head,0,19);

    printListForward(head);
    printListBackward(head);

    return 0;
}

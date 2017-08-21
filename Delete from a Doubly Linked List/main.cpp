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
            cout<<"<-";
        head=head->prev;
    }
    cout<<"\n";
}
node * deleteFirst(node *head,int data)
{
    node * ret=head;
    while(head!=NULL)
    {
        if(head->data==data)
            break;
        head=head->next;
    }
    if(head==NULL)
    {
        cout<<"Node with data:"<<data<<" is not found\n";
    }
    else
    {
        if(head->prev!=NULL)
            head->prev->next=head->next;
        if(head->next!=NULL)
            head->next->prev=head->prev;
        if(head->prev==NULL)// head pointer must change
            ret=head->next;
        delete head;
    }
    return ret;
}
int main()
{
   node * head=NULL;
   head =insertionAtFront(head,5);
   head=insertionAtFront(head,4);
   head=insertionAtFront(head,6);
   head =insertionAtFront(head,3);
   head =insertionAtFront(head,2);
   head =insertionAtFront(head,1);
   printListForward(head);
   printListBackward(head);

   head=deleteFirst(head,6);

   printListForward(head);
   printListBackward(head);
    return 0;
}

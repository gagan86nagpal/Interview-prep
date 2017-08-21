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
node* reverseAll(node* head)
{
    node * temp;
    node * newHead=head;
    while(head!=NULL)
    {
        if(head->next==NULL)
            newHead=head;
       swap(head->next,head->prev);
        head=head->prev;    // since next and prev has been swapped
    }
    return newHead;
}
int main()
{
   node * head=NULL;
   head =insertionAtFront(head,5);
   head=insertionAtFront(head,4);
   head=insertionAtFront(head,3);
   printListForward(head);
   printListBackward(head);
   head=reverseAll(head);

   printListForward(head);
   printListBackward(head);
    return 0;
}

#include <iostream>

using namespace std;
struct node
{
    int data;
    node * next;
};
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
node * insertAtBeginning(node* head,int data)
{
    node * temp = new node();
    temp->data = data;
    temp->next= head;
    return temp;
}
node * rotateList(node *head)
{
    if(head==NULL ||head->next==NULL)
        return head;
    node* originalHead=head;
    node * prev=NULL;
    while(head->next!=NULL)
    {
        prev=head;
        head=head->next;
    }
    head->next=originalHead;
    prev->next=NULL;
    return head;
}
int main()
{
    node * head = NULL;
    head = insertAtBeginning(head,2);
    head = insertAtBeginning(head,4);
    head = insertAtBeginning(head,10);
    head = insertAtBeginning(head,6);
    head = insertAtBeginning(head,8);
    head = insertAtBeginning(head,2);
    printList(head);

    head  = rotateList(head);
    printList(head);
    return 0;
}

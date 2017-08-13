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
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;
}

node * reverseLinkedList(node * head)
{
    node * first,* second,* third;
    first=NULL;
    second=head;
    third=second;
    while(second!=NULL)
    {
        third=third->next;
        second->next=first;
        first=second;
        second=third;
    }

    return first;
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
    node * head=NULL;
    head = insertAtBeginning(head,1);
    head = insertAtBeginning(head,2);
    head = insertAtBeginning(head,3);
    head = insertAtBeginning(head,4);
    head = insertAtBeginning(head,5);
    head = insertAtBeginning(head,6);
    head = insertAtBeginning(head,7);
    printList(head);

    head = reverseLinkedList(head);
    printList(head);
    return 0;
}

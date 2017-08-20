/*
Given a singly linked list, rotate the linked list counter-clockwise by k nodes.
Where k is a given positive integer. For example, if the given linked list is 10->20->30->40->50->60 and k is 4,
the list should be modified to 50->60->10->20->30->40. Assume that k is smaller than the count of nodes in linked list.
*/
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
node* insertAtBeginning(node* head,int data)
{
    node* temp = new node();
    temp->data=data;
    temp->next=head;
    return temp;
}
node *rotateList(node * head,int k)
{
    if(k==0)
        return head;
    node *ret;
    node *originalHead=head;
    node * prevRet;

    while(--k)
        head=head->next;
    prevRet=head;
    ret=head->next;
    if(ret==NULL)
        return originalHead;
    while(head->next!=NULL)
        head=head->next;
    head->next=originalHead;

    prevRet->next=NULL;
    return ret;
}
int main()
{
    node * head = NULL;
    int k;
    head=insertAtBeginning(head,60);
    head=insertAtBeginning(head,50);
    head=insertAtBeginning(head,40);
    head=insertAtBeginning(head,30);
    head=insertAtBeginning(head,20);
    head=insertAtBeginning(head,10);
    printList(head);
    k=2;
    head=rotateList(head,k);
    printList(head);
    return 0;
}

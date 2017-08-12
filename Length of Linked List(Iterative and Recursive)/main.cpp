#include <iostream>

using namespace std;
struct node
{
    int data;
    node* next;
};
node* insertInBegining(node* head,int data)
{
    node * temp  = new node();
    temp->data=data;
    temp->next=head;
    head = temp;
    return head;
}
void printList(node * head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<"\n";
}

int sizeOfLinkedListIterative(node * head)
{
    int cnt=0;
    while(head!=NULL)
    {
        cnt++;
        head=head->next;
    }
    return cnt;
}
int sizeOfLinkedListRecursive(node * head)
{
    if(head!=NULL)
        return 1 +sizeOfLinkedListRecursive(head->next);
    return 0;
}
int main()
{
    node * head = NULL;
    head = insertInBegining(head,7);
    head = insertInBegining(head,6);
    head = insertInBegining(head,54);
    head = insertInBegining(head,5);
    head = insertInBegining(head,4);
    head = insertInBegining(head,3);
    head = insertInBegining(head,2);
    head = insertInBegining(head,1);
    printList(head);

    cout<<"Size of Linked List (by Iterative Method): "<<sizeOfLinkedListIterative(head)<<"\n";
    cout<<"Size of Linked List (by Recursive Method): "<<sizeOfLinkedListRecursive(head)<<"\n";

    node* head1 = NULL;  // empty Linked List
    cout<<"Size of Empty Linked List (by Iterative Method): "<<sizeOfLinkedListIterative(head1)<<"\n";
    cout<<"Size of Empty Linked List (by Recursive Method): "<<sizeOfLinkedListRecursive(head1)<<"\n";

    node* head2 = new node();
    head2->next=NULL;
    head2->data=10;
    // 1 element linked list

    cout<<"Size of Empty Linked List (by Iterative Method): "<<sizeOfLinkedListIterative(head2)<<"\n";
    cout<<"Size of Empty Linked List (by Recursive Method): "<<sizeOfLinkedListRecursive(head2)<<"\n";

    return 0;
}

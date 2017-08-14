#include <iostream>

using namespace std;
struct node
{
    int data;
    node * next;
};

node * insertAtBegining(node * head,int data)
{
    node * temp = new node();
    temp->data=data;
    temp->next=head;
    return temp;
}
void printList(node * head)
{
    cout<<"Linked List :";
    while(head!=NULL)
    {
        cout<<head->data;
        if(head->next!=NULL)
            cout<<" -> ";
        head=head->next;
    }
    cout<<"\n";
}
// Very elegant and clean code
node * reverseKsize(node * head,int k)
{
    if(k==0)
        return head;
    if(head==NULL)
        return head;
    int i=k;
    node *first=NULL, *second=head, *third;
    node * originalHead = head;
    while(second!=NULL && k>0)
    {
        third=second->next;
        second->next=first;
        first=second;
        second=third;
        k--;
    }
    originalHead->next=reverseKsize(second,i);
    return first;
}
int main()
{
    node * head = NULL;
    head=insertAtBegining(head,7);
    head=insertAtBegining(head,6);
    head=insertAtBegining(head,5);
    head=insertAtBegining(head,4);
    head=insertAtBegining(head,3);
    head=insertAtBegining(head,2);
    head=insertAtBegining(head,1);
    head=insertAtBegining(head,0);
    printList(head);


    head = reverseKsize(head,2);
    printList(head);


    return 0;

}

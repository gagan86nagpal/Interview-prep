#include <iostream>

using namespace std;
struct node
{
    int data;
    node *next;
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
node * insertAtBegining(node * head,int data)
{
    node *temp = new node();
    temp->data=data;
    temp->next=head;
    return temp;
}
// return NULL id no loop
// else it returns the meeting point of one and two pointers
node* detect(node * head)
{
    if(head==NULL ||head->next==NULL)
        return NULL;
    node *one = head;
    node *two = head;
    do
    {
        if(one!=NULL)
            one=one->next;
        if(two!=NULL)
            two=two->next;
        if(two!=NULL)
            two=two->next;
    }while(two!=NULL && one!=two);
    return two;
}

// Only be called if there is guarantee that loop exists
void removeLoop(node * head,node * meet)
{
    if(head==meet) // Linked List is Circular
    {
        cout<<"Linked List is Circular\n";
        while(meet->next!=head)
            meet=meet->next;
    }
    else  // Linked List is not Circular
    {
        while(head->next!=meet->next)
        {
            head=head->next;
            meet=meet->next;
        }
    }
    cout<<"Faulty Node is:"<<meet->data<<"\n";
    meet->next=NULL;
}
int main()
{
    node *head =NULL;
    head = insertAtBegining(head,6);
    head = insertAtBegining(head,5);
    head = insertAtBegining(head,4);
    head = insertAtBegining(head,3);
    head = insertAtBegining(head,2);
    head = insertAtBegining(head,1);
    head = insertAtBegining(head,0);
    // Uncomment to make a loop
    head->next->next->next->next->next->next->next = head;
    node * ret=detect(head);
    if(ret==NULL)
    {
        cout<<"No Loop Exists\n";
    }
    else
    {
        cout<<"Loop Exists and pointers meet at:"<<ret->data<<"\n";
        cout<<"Removing Loop\n";
        removeLoop(head,ret);
    }
    printList(head);
    return 0;
}

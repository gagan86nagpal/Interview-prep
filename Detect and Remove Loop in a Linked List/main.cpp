/*
Write a function detectAndRemoveLoop() that checks whether a given Linked List contains loop
 and if loop is present then removes the loop and returns true. And if the list does not
 contain loop then returns false
*/

// Using stl Map solution
#include <iostream>
#include <map>
using namespace std;

struct node
{
    int data;
    node * next;
};
map <node*,int> m;

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

bool detectAndRemove(node *head)
{
    node * prev=NULL;
    while(head!=NULL)
    {
        if(m.find(head) ==m.end()) // no key found
        {
            m[head]=1;
        }
        else  // two times
        {
            m[head]++;
            break;
        }
        prev=head;
        head=head->next;
    }
    if(head==NULL)
    {
        cout<<"No Loop\n";
        return false;
    }
    else
    {
        cout<<"loop at Node representing value:"<<prev->data<<"\n";
        prev->next=NULL;
        return true;
    }
}
int main()
{
    node *head= NULL;
    head=insertAtBegining(head,4);
    head=insertAtBegining(head,3);
    head=insertAtBegining(head,2);
    head=insertAtBegining(head,1);
    head=insertAtBegining(head,0);
    head->next->next->next->next->next = head->next->next; // Introducing a loop
    cout<<detectAndRemove(head)<<"\n";
    printList(head);

    for (auto key : m)
    {
        cout<<key.first<<" "<<key.second<<"\n";
    }
    return 0;
}

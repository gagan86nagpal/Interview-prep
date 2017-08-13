// We always attempt to change the links rather than swapping the data as our goal is to improve our understanding on
// how pointer works rather than in general algorithm of merge sort

// Could this code be more messier
#include <iostream>

using namespace std;

struct node
{
    int data;
    node* next;
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
node* insertAtBeginning(node * head,int data)
{
    node * temp = new node();
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;
}
// This code is very redundant,
// A lot of improvement can be done by just maintaining loop invariant.
// Will update the improved version if possible.
node * mergeSorted(node * head1,node * head2)
{
    node * head=NULL;
    node * tail=NULL;
    if(head1==NULL && head2==NULL)
        return NULL;
    if(head1==NULL)
    {
        head = new node();
        head->next=NULL;
        head->data=head2->data;
        head2= head2->next;
        tail=head;
        while(head2!=NULL)
        {
            tail->next = new node();
            tail=tail->next;
            tail->next=NULL;
            tail->data = head2->data;
            head2=head2->next;
        }
        return head;
    }
    if(head2==NULL)
    {
        head = new node();
        head->next=NULL;
        head->data=head1->data;
        head1= head1->next;
        tail=head;
        while(head1!=NULL)
        {
            tail->next = new node();
            tail=tail->next;
            tail->next=NULL;
            tail->data = head1->data;
            head1=head1->next;
        }
        return head;
    }
    // initializing head pointer
    if(head1->data < head2->data)
    {
        head=new node();
        head->data = head1->data;
        head1=head1->next;
        tail = head;
    }
    else
    {
        head=new node();
        head->data = head2->data;
        head2=head2->next;
        tail = head;
    }

    // Basic algorithm
    while( (head1!=NULL )&& (head2!=NULL ))
    {
        if(head1->data < head2->data)
        {
            tail->next = new node();
            tail=tail->next;
            tail->next=NULL;
            tail->data = head1->data;
            head1=head1->next;
        }
        else
        {
            tail->next = new node();
            tail=tail->next;
            tail->next=NULL;
            tail->data = head2->data;
            head2=head2->next;
        }
    }
    // if second list is exhausted first
    while(head1!=NULL)
    {
        tail->next = new node();
        tail=tail->next;
        tail->next=NULL;
        tail->data = head1->data;
        head1=head1->next;
    }
    // if first list is exhausted first
    while(head2!=NULL)
    {
        tail->next = new node();
        tail=tail->next;
        tail->next=NULL;
        tail->data = head2->data;
        head2=head2->next;
    }
    return head;
}
node * getFirstHalfEnd(node * head)
{
    if(head==NULL)
        return NULL;
    node * traverse=head;
    while(head!=NULL)
    {
        head=head->next;
        if(head!=NULL)
            head=head->next;
        if(head!=NULL)
        traverse=traverse->next;
    }
    return traverse;
}
node * getNewList(node * first,node * last)
{
    if(first==NULL)
        return NULL;
    node * originalHead =NULL;
    node * head = new node();
    originalHead=head;
    head->data = first->data;
    head->next=NULL;
    while(first!=last)
    {
        first=first->next;
        if(first==NULL)
            break;
        head->next = new node();
        head = head->next;
        head->data=first->data;
        head->next=NULL;
    }
    if(first!=last&&last!=NULL)
    {
        head->next = new node();
        head=head->next;
        head->data= last->data;
        head->next=NULL;
    }
    return originalHead;
}


node * mergeSort(node * first,node * firstEnd, node * secondEnd)
{
    if(first==NULL)
        return NULL;
    if(first==firstEnd && firstEnd->next==NULL)
        return first;
    node * second = firstEnd->next;
    node * firstList = getNewList(first,firstEnd);
    node * secondList = getNewList(second,secondEnd);


    firstList=mergeSort(firstList,getFirstHalfEnd(firstList),NULL);
    secondList=mergeSort(secondList,getFirstHalfEnd(secondList),NULL);

    return mergeSorted(firstList,secondList);
}

int main()
{
    node * head=NULL;
    node * sorted = NULL;
    head  =insertAtBeginning(head,1);
     head  =insertAtBeginning(head,4);
     head  =insertAtBeginning(head,12);
     head  =insertAtBeginning(head,14);
     head  =insertAtBeginning(head,11);
     head  =insertAtBeginning(head,411);
     head  =insertAtBeginning(head,5);
     head  =insertAtBeginning(head,2);
     head  =insertAtBeginning(head,453);
    cout<<"Initial List:\n";
    printList(head);
    sorted = mergeSort(head,getFirstHalfEnd(head),NULL);
    cout<<"Sorted List:\n";
    printList(sorted);
    return 0;
}

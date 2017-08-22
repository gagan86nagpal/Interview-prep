#include <iostream>

using namespace std;
struct node
{
    int data;
    node* next;
    node* prev;
};

// add a new node at the end of the list
node *append(node * head,int data)
{
    node * originalHead =head;
    while(head!=NULL&&head->next!=NULL)
        head=head->next;
    node* temp=new node();
    temp->data=data;
    temp->prev=head;
    if(head!=NULL)
        head->next=temp;
    temp->next=NULL;
    if(head==NULL)
        originalHead=temp;
    return originalHead;
}
void printListForward(node* head )
{
    if(head==NULL)
    {
        cout<<"List is empty\n";
        return;
    }
    while(head!=NULL)
    {
        cout<<head->data;
        if(head->next!=NULL)
            cout<<" -> ";
        head=head->next;
    }
    cout<<"\n";
}
// Handles all the cases and is probably the brain of merge sort
// returns a new list that is result of sorted concatenation of list represented by first and second
// first and second should be a proper list which must have null pointer at the end
node* mergeTwoSortedDoublyLinkedList(node* first, node* second)
{
    node* ret =NULL;
    node* temp=NULL;
    node* newHead;
    if(first==NULL && second==NULL)
    {
        return NULL;
    }
    if(first==NULL)
    {
        temp= new node();
        temp->data=second->data;
        temp->next=NULL;
        temp->prev=NULL;
        return temp;
    }
    if(second==NULL)
    {
        temp= new node();
        temp->data=first->data;
        temp->next=NULL;
        temp->prev=NULL;
        return temp;
    }
    while(first!=NULL&&second!=NULL)
    {
        if(first->data >second->data)
        {
            temp= new node();
            temp->data=second->data;
            temp->next=NULL;
            temp->prev=ret;
            if(ret!=NULL)
            {
                ret->next=temp;
                ret=ret->next;
            }
            else
            {
                ret=temp;
                newHead=ret;
            }
            second=second->next;

        }
        else
        {
            temp= new node();
            temp->data=first->data;
            temp->next=NULL;
            temp->prev=ret;
            if(ret!=NULL)
            {
                ret->next=temp;
                ret=ret->next;
            }
            else
            {
                ret=temp;
                newHead=ret;
            }
            first=first->next;
        }
    }
    while(first)
    {
        temp= new node();
        temp->data=first->data;
        temp->next=NULL;
        temp->prev=ret;
        first=first->next;
        ret->next=temp;
        ret=ret->next;
    }
    while(second)
    {
        temp= new node();
        temp->data=second->data;
        temp->next=NULL;
        temp->prev=ret;
        second=second->next;
        ret->next=temp;
        ret=ret->next;
    }

    // Setting the previous Links
    temp=newHead;
    temp->prev=NULL;
    while(temp!=NULL)
    {
        if(temp->next!=NULL)
        {
            temp->next->prev=temp;
        }
        temp=temp->next;
    }
    return newHead;
}

// Returns the mid of the Linked List
// similar mid=(first+last)/2
node* getMid(node* first,node* last)
{
    if(first==last)
        return first;
    node* one=first, * two=first;
    while(two!=last)
    {
        if(two!=last)
            two=two->next;
        if(two!=last)
            two=two->next;
        else
            break;
        one=one->next;
    }
    return one;
}
// Recursive function for merge sort
node* mergeSort(node* first, node* last)
{
    node* mid=getMid(first,last);
    node *list1,*list2;
    if(first!=last)
        list1=mergeSort(first,mid);
    if(first!=last)
        list2=mergeSort(mid->next,last);
    if(first==last)  // There is just one node , so make a new list and start the recursive process from here
    {
        node * temp = new node();
        temp->data=first->data;
        temp->next=NULL;
        temp->prev=NULL;
        list1=temp;   // list1 is just one element
        list2=NULL;   // list2 is NULL
        // merging handles this case and other cases well
    }
    node* list3=mergeTwoSortedDoublyLinkedList(list1,list2);
    return list3;
}
int main()
{
    node * head=NULL;
    head=append(head,1);
    head=append(head,5);
    head=append(head,1);
    head=append(head,65);
    head=append(head,12);
    head=append(head,14);
    head=append(head,12);
    head=append(head,14);
    printListForward(head);

    // Finding the Last node
    node* first=head;
    node* last = head;
    while(last->next!=NULL)
        last=last->next;
    node* sorted=mergeSort(first,last);


    printListForward(sorted);

    return 0;
}

#include <iostream>

using namespace std;
struct node
{
    int data;
    node* next;
    node* prev;
};
node* append(node* head,int data)
{
    node* originalHead = head;

    while(head!=NULL &&head->next!=NULL)
        head=head->next;
    node * temp  = new node();
    temp->data=data;
    temp->prev=head;
    if(head!=NULL)
        head->next=temp;
    temp->next=NULL;
    if(originalHead==NULL)
        originalHead=temp;
    return originalHead;
}
void printList(node* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        if(head->next)
            cout<<"->";
        head=head->next;
    }
    cout<<"\n";
}

// n*logn
// For a given linked list , we find the middle element by traversing , First is the middle
// Now we make this as root as proceed for left half and right half
// When List is empty we return NULL and stops recursion.

// For every list , we are traversing hence time is n*logn
// Same recurrence as that of merge sort
node* convertListToTree(node* head,node* end)
{
    node* first=NULL;  // 1x speed
    node* second=head;   // 2x speed
    node* originalHead =head;
    while(second!=end)
    {
        if(!first)
            first=originalHead;
        second=second->next;
        if(second!=end)
            second=second->next;
        else
            break;
        first=first->next;
    }
    // first should be at middle of the Linked List
    // if the list is NUll it will be NULL
    if(!first)
        return NULL;
    first->prev=convertListToTree(head,first);
    first->next=convertListToTree(first->next,end);
    return first;
}

// Making inorder tree traversal to verify , it's tree
// Tree will be balanced as middle element is chosen as root
void inorder(node* root)
{
    if(!root)
        return ;
    inorder(root->prev);
    cout<<root->data<<" ";
    inorder(root->next);
}
int main()
{
    node* head = NULL;
    node* root=NULL;
    head=append(head,2);
    head= append(head,4);
    head=append(head,7);
    head=append(head,12);
    head=append(head,14);
    head=append(head,20);
    head=append(head,23);
    printList(head);

    root= convertListToTree(head,NULL);
    inorder(root);
    return 0;
}

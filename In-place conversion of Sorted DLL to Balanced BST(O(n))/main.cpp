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
// Simple method to return the number of nodes in a DLL
// It is called only once
int countNodes(node* head)
{
    int cnt=0;
    while(head)
    {
        head=head->next;
        cnt++;
    }
    return cnt;
}
// Main Recursive function to create a BBST
// It builds the BST from leaves to root
// First it creates the left subtree , then root , then right subtree
// Since , it creates the left subtree and then it moves ahead
// We don't need to find the middle pointer as we can just increment it
// Hence , Every recursive call is constant Operation , making it is an O(n) algorithm
// head pointer is alias as we are incrementing it and want to retains its value, we
// could have declared it globally also.
node* convertListToTreeRecursive(node* &head,int n)
{
    if(n<=0)
        return NULL;
    node* root;
    node* left = convertListToTreeRecursive(head,n/2);  // make left subtree, head is pointing to root only
    root=head;                                          // make root pointer to head
    head=head->next;                                     // increment head
    root->prev=left;                                     // Set the left subtree of root
    root->next= convertListToTreeRecursive(head,n- n/2 -1); // RIght subtree is constructed here
    return root;
}

// Driver function
node* convertListToTree(node* head)
{
    int n= countNodes(head);
    return convertListToTreeRecursive(head,n);
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
    root= convertListToTree(head);

    inorder(root);
    return 0;
}

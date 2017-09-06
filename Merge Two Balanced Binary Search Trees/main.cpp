#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Idea is to first create a sorted vector of element of both BSTs
// This can be done by inorder traversals of BSTs.
// Now, Creating a doubly Linked List of the ascending order elements
// Converting this DLL into a Balanced BST also takes linear time.


struct node
{
    int data;
    node* left,*right;
};
node* newNode(int data)
{
    node* temp = new node();
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}

// Insertion in DLL
void insertAtBeginning(node* &head,int data)
{
    node* temp = new node();
    temp->data = data;
    temp->left=NULL;
    temp->right=head;
    if(head)
        head->left=temp;
    head=temp; // It will change the local copy as it is being passed as reference
}
// Creating DLL from array
void createDll(node* &head,vector <int> & sorted)
{
    int i=sorted.size()-1;
    while(i>=0)
        insertAtBeginning(head,sorted[i--]);
}

// from leaves to root conversion takes linear time
node* convertDllToBst(node* &head,int n)
{
    if(n<=0)
        return NULL;
    node* left=convertDllToBst(head,n/2);
    node* root= head;
    root->left=left;
    head=head->right;
    root->right = convertDllToBst(head,n-n/2 -1);
    return root;
}
// To verify the tree
void inorderPrint(node* root)
{
    if(!root)
        return ;
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}
// Printing the Doubly Likned List
void printDll(node* head)
{
    cout<<"DLL:";
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        if(head->right)
            cout<<" -> ";
        head=head->right;
    }
    cout<<"\n";
}
// Inorder traversal to push elemets in the vector in ascending order
void inorder(node* root,vector <int> &v)
{
   if(!root)
    return ;
   inorder(root->left,v);
   v.push_back(root->data);
   inorder(root->right,v);
}
// v1 and v2 are ascendingly sorted , sorted vector is a sorted vector created by merging o
void mergeSorted(vector<int> & sorted,vector<int> & v1,vector<int> &v2)
{
    int i,j;
    i=0;
    j=0;
    while(i<(int)v1.size() && j<(int)v2.size())
    {
        if(v1[i]<v2[j])
            sorted.push_back(v1[i++]);
        else
            sorted.push_back(v2[j++]);
    }
    while(i<(int)v1.size())
        sorted.push_back(v1[i++]);
    while(j<(int)v2.size())
        sorted.push_back(v2[j++]);
}

// to verify the tree
void preorderPrint(node* root)
{
    if(!root)
        return ;
    cout<<root->data<<" ";
    preorderPrint(root->left);
    preorderPrint(root->right);
}
// Main Driver function
node* mergeBst(node* & root1,node* root2)
{
    vector <int> sorted,inorder1,inorder2;
    inorder(root1,inorder1);  // O(n)
    inorder(root2,inorder2);  // O(m)
    mergeSorted(sorted,inorder1,inorder2);  // O(n+m)
    node* head=NULL;
    createDll(head,sorted);  // O(n+m)
    printDll(head);

   node* root=  convertDllToBst(head,sorted.size());    // O(n+m)
   cout<<"BST Created!!\n";
   return root;
}
int main()
{
    /* Create following tree as first balanced BST
           100
          /  \
        50    300
       / \
      20  70
    */
    struct node *root1  = newNode(100);
    root1->left         = newNode(50);
    root1->right        = newNode(300);
    root1->left->left   = newNode(20);
    root1->left->right  = newNode(70);

    /* Create following tree as second balanced BST
            80
           /  \
         40   120
    */
    struct node *root2  = newNode(80);
    root2->left         = newNode(40);
    root2->right        = newNode(120);

    node* root=mergeBst(root1,root2);
    cout<<"Inorder:";
    inorderPrint(root);
    cout<<"\nPreorder:";
    preorderPrint(root);
    return 0;
}

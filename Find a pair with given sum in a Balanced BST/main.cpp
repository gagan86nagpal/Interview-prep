#include <iostream>
#include <vector>
using namespace std;
// Idea is to Store the inorder in a vector
// Now , initialize two pointers at beginning and at end.
// If sum , is greater than sum of pointers , decrement the end pointer
// If sum is less , then increment the beginning pointer
// Else found

// TIme is O(n) and space is O(n)
vector <int> inorder_vector;
struct node
{
    int data;
    node* left,*right;
};
node* NewNode(int data)
{
    node* temp = new node();
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}
void inorder(node* root)
{
    if(!root)
        return ;
    inorder(root->left);
    inorder_vector.push_back(root->data);
    inorder(root->right);
}
bool isPairExists(node* root,int target)
{
    inorder(root);
    int beg=0;
    int sum=0;
    int end=inorder_vector.size()-1;
    while(beg<end)
    {
        sum=inorder_vector[beg]+inorder_vector[end];
        if(sum==target)
        {
            cout<<"pair :"<<inorder_vector[beg]<<" , "<<inorder_vector[end]<<"\n";
            return true;
        }
        else if(sum > target)
            end--;
        else
            beg++;
    }
    cout<<"Pair Doesn't Exists\n";
        return false;
}
int main()
{
   /*
                   15
                /     \
              10      20
             / \     /  \
            8  12   16  25    */
    struct node *root =  NewNode(15);
    root->left = NewNode(10);
    root->right = NewNode(20);
    root->left->left = NewNode(8);
    root->left->right = NewNode(12);
    root->right->left = NewNode(16);
    root->right->right = NewNode(25);

    int target = 21;
    cout<<isPairExists(root,target)<<"\n";

    target=22;
    cout<<isPairExists(root,target)<<"\n";
    return 0;
}

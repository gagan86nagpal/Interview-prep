#include <iostream>

using namespace std;
 // we will use a Linked List representation of our own linked list
 struct node
 {
     int data;
     node* next;
 };

// THe only difference in this approach is we cannot traverse the graph with indices but in dfs we don't need that traversal by indices
// It is rare to use the indexing in graph.
// have to maintain a last pointer as to make push_back in constant time
// Number of nodes connected can be maintained by a normal data member , which will be incremented on every push_back
// Head should be made private and a getter function should return it's value
 class LinkedList
 {
 private:
    node* head;
    node* last;
 public:
     node* getHead()
     {
         return head;
     }
     void push_back(int data)
     {
         node* temp = new node();
         temp->data=data;
         temp->next=NULL;
         if(head==NULL)
            head=last=temp;
         else
            last->next=temp;
     }
 };

LinkedList graph[100]; // 100 nodes
int vis[100]; // 100 nodes
void dfs(int root)
{
    if(vis[root])
        return;
    vis[root]=1;
    cout<<root<<" ";
    node* temp = graph[root].getHead();
    while(temp!=NULL)
    {
        dfs(temp->data);
        temp=temp->next;
    }
}
int main()
{
    graph[0].push_back(1);
    graph[0].push_back(2);
    graph[1].push_back(2);
    graph[2].push_back(0);
    graph[2].push_back(3);
    graph[3].push_back(3);
    dfs(2);
    return 0;
}

#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int input[100];
struct node
{
    int data;
    node * next;
};
class Queue
{
    int n=0;
    node * f=NULL;
    node * r=NULL;
public:
    int length()
    {
        return n;
    }
    int getFront()
    {
        if(f)
            return f->data;
        else
            cout<<"Queue is empty\n";
    }
    int getRear()
    {
        if(r)
            return r->data;
        else
            cout<<"Queue is empty\n";
    }
    bool isEmpty()
    {
        return f==NULL;
    }
    void enqueue(int x)
    {
        node * temp = new node();
        temp->data=x;
        temp->next=NULL;
        if(r==NULL) // list is empty
        {
            r=f=temp;
        }
        else
        {
            r->next=temp;
            r=r->next;
        }
        n++;
    }
    int dequeue()
    {
        node* temp =f;
        int ret=-1;
        if(temp)
        {
            f=f->next;
            ret=temp->data;
            delete temp;
            if(f==NULL)  // just one node in list;
                r=NULL;
            n--;
        }
        else
        {
            cout<<"Queue is Empty\n";
        }
        return ret;
    }
    void print()
    {
        cout<<"Queue Status:";
        node *temp = f;
        if(f)
            cout<<"Front:"<<f->data<<", Rear:"<<r->data<<"\n";
        else
            cout<<"Empty\n";
        while(temp)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }
};
int main()
{
    int i,n;
    cin>>n;
    int a,b;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        input[i]=a-b;
    }
    for(i=n;i<2*n-1;i++)
        input[i]=input[i-n];

    int ans=-1;
    Queue q;
    q.enqueue(0); // base case
    for(i=0;i<2*n-1;i++)
    {
        a=q.getRear() + input[i];
        if(a>=0)
        {
            q.enqueue(a);
            if(q.length()==n+1)
            {
                ans=i-n+1;
                break;
            }
        }
        else
        {
            while(!q.isEmpty())
            {
                q.dequeue();
            }
            q.enqueue(0);// maintaining base case
        }
    }
    if(ans==-1)
        cout<<"No Circular tour exists\n";
    else
        cout<<"Circular Tour exists from index:"<<ans;
    return 0;
}

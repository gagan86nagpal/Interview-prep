#include <iostream>

using namespace std;
struct node
{
    int data;
    node * next;
};
class Queue
{
    node * f=NULL;
    node * r=NULL;
public:
    int front()
    {
        if(f)
            return f->data;
        else
            cout<<"Queue is empty\n";
    }
    int rear()
    {
        if(r)
            return r->data;
        else
            cout<<"Queue is empty\n";
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
    Queue q;
    q.enqueue(1);
    q.print();
    q.enqueue(4);
    q.print();
    q.enqueue(3);
    q.print();
    cout<<"de:"<<q.dequeue()<<"\n";
    q.print();
    q.dequeue();
    q.print();
    q.dequeue();
    q.print();
    q.enqueue(4);
    q.print();
    return 0;
}

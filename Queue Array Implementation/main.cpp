#include <iostream>

using namespace std;
class Queue
{
private:
    static const int capacity=9;
    int r=-1;
    int f=-1;
    int a[capacity];
public:
    int rear()
    {
        if(r!=-1)
            return a[r];
        else
            cout<<"Queue is Empty\n";
        return -1;
    }
    int front()
    {
        if(f!=-1)
            return a[f];
        else
            cout<<"Queue is Empty\n";
        return -1;
    }
    void enqueue(int x)
    {
        if(f==r+1 ||(f==0 && r==capacity-1) )
            cout<<"Queue is full\n";
        else
        {
            r++;
            if(r==capacity)
                r=0;
            a[r]=x;
            if(f==-1)
                f=0;
        }
    }
    int dequeue()
    {
        if(f==r&&f==-1)
            cout<<"Queue is empty\n";
        int ret;
        ret=a[f];
        if(f==r)
        {
            f=-1;
            r=-1;
            return ret;
        }
        f++;
        if(f==capacity)
            f=0;
        return ret;
    }
    void print()
    {
        cout<<"front:"<<f<<", rear:"<<r<<"\n";
        if(f==r &&(f==-1 ) )
        {
            cout<<"Queue is empty";
        }
        else
        {
            int temp=f;
            while(temp!=r)
            {
                cout<<a[temp]<<" ";
                temp++;
                if(temp==capacity)
                    temp=0;
            }
            cout<<a[temp]<<" ";
        }
        cout<<"\n";
    }
};
int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.print();
    q.dequeue();
    q.print();
    q.enqueue(6);
    q.enqueue(6);
    q.enqueue(7);
    q.enqueue(2);
    q.enqueue(6);
    q.print();
    q.enqueue(5);
    q.print();
    q.enqueue(3);
    q.print();
    q.enqueue(4);
    q.print();
    q.dequeue();
    q.print();
    q.dequeue();
    q.print();
    return 0;
}

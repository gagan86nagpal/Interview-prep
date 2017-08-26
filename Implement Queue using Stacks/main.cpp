#include <iostream>

using namespace std;
// dequeue is costly here
class Stack
{
private:
    int top=-1;
    static const int max_limit=10;
    int a[max_limit];
public:
    bool isEmpty()
    {
        return top==-1;
    }
    void push(int x)
    {
        if(top==max_limit-1)
            cout<<"OverFlow\n";
        else
            a[++top]=x;
    }
    int pop()
    {
        int ret=-1;  // default value to return in case of underflow
        if(top==-1)
            cout<<"UnderFlow\n";
        else
            ret=a[top--];
        return ret;
    }
    int getTop()
    {
        int ret=-1; // default value to return in case of underflow
        if(top==-1)
            cout<<"Underflow\n";
        else
            ret=a[top];
        return ret;
    }
    void printStack()
    {
        int temp=top;
        cout<<"Stack: ";
        if(temp==-1)
            cout<<"Stack is empty";
        while(temp!=-1)
            cout<<a[temp--]<<" ";
        cout<<"\n";
    }
};
// using two stacks
class Queue
{
private:
    Stack s1;
    Stack s2;

public:
    void enqueue(int x)
    {
        s1.push(x);
    }
    int dequeue()
    {
        while(!s1.isEmpty())
        {
            s2.push(s1.pop());
        }
        int ret= s2.pop();
        while(!s2.isEmpty())
        {
            s1.push(s2.pop());
        }
        return ret;
    }
    int getFront()
    {
        while(!s1.isEmpty())
            s2.push(s1.pop());
        int ret=s2.getTop();
        while(!s2.isEmpty())
            s1.push(s2.pop());
        return ret;
    }
    int getRear()
    {
        return s1.getTop();
    }
    void print()   //  front -> rear
    {
        cout<<"Queue:";
        if(s1.isEmpty())
            cout<<" Empty";
        while(!s1.isEmpty())
            s2.push(s1.pop());
        while(!s2.isEmpty())
        {
            cout<<s2.getTop()<<" ";
            s1.push(s2.pop());
        }
        cout<<"\n";
    }
    void printInfo()
    {
        cout<<"Front:"<<getFront()<<", Rear:"<<getRear()<<"\n";
    }

};
int main()
{
    Queue q;
    q.print();
    q.enqueue(3);
    q.enqueue(1);
    q.enqueue(5);

    q.print();
    q.printInfo();

    q.enqueue(6);

    q.print();
    q.printInfo();

    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.print();
    q.printInfo();

    q.dequeue();

    q.print();
    q.printInfo();
    return 0;
}

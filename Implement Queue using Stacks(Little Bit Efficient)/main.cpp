#include <iostream>

using namespace std;

// Had to implement getBottom() in Stack class
// So as to print Queue data structure for debugging
// enqueue and dequeue are are not using getBottom()
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
    int getBottom()
    {
        if(!isEmpty())
        {
            int x = pop();
            int ret;
            if(!isEmpty())
                ret=getBottom();
            else
            {
                push(x);
                return x;
            }
            push(x);
            return ret;
        }
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
       if(s2.isEmpty())
       {
           while(!s1.isEmpty())
                s2.push(s1.pop());
       }
        return s2.pop();
    }
    int getFront()
    {
        if(s2.isEmpty())
           return s1.getBottom();
        return s2.getTop();
    }
    int getRear()
    {
        if(!s1.isEmpty())
            return s1.getTop();
        return s2.getBottom();
    }
    void printInfo()
    {
        printInternal();
        cout<<"Front:"<<getFront()<<", Rear:"<<getRear()<<"\n";

    }
    void printInternal()
    {
        s1.printStack();
        s2.printStack();
    }

};
int main()
{
    Queue q;
    q.enqueue(1);
    q.printInfo();
    q.enqueue(2);
    q.printInfo();
    q.enqueue(4);
    q.printInfo();
    q.enqueue(5);
    q.printInfo();
    cout<<"Dequeue:"<<q.dequeue()<<"\n";
    q.printInfo();
    q.enqueue(7);
    q.printInfo();
    cout<<"Dequeue:"<<q.dequeue()<<"\n";
    q.printInfo();
    return 0;
}

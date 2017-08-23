#include <iostream>

using namespace std;
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
int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.printStack();
    s.pop();
    s.push(23);
    s.printStack();
    return 0;
}

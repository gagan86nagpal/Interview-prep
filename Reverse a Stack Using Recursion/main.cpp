#include <iostream>

using namespace std;
/*
Write a program to reverse a stack using recursion.
 You are not allowed to use loop constructs like while, for..etc,
 and you can only use the following ADT functions on Stack S:
isEmpty(S)
push(S)
pop(S)
*/

/*
Idea is to first implement insertion at bottom of stack using three methods.
Then pop all elements to function stack and as the recursion unfold push these elements to bottom of stack.

*/
int input[100];
int output[100];
class Stack{
private:
    int top=-1;
    static const int max=1000;
    int a[1000];
public:
    void push(int c)
    {
        a[++top]=c;
    }
    int pop()
    {
        return a[top--];
    }
    bool isEmpty()
    {
        return top==-1;
    }
    void print()
    {
        int temp=top;
        cout<<"Stack: ";
        while(temp>=0)
            cout<<a[temp--]<<" ";
        cout<<"\n";
    }
};
void pushBottom(Stack &st,int x)
{
    if(!st.isEmpty())
    {
        int a = st.pop();
        pushBottom(st,x);
        st.push(a);
    }
    else
        st.push(x);
}

void reverseStack(Stack &st)
{
    if(!st.isEmpty())
    {
        int a=st.pop();
        reverseStack(st);
        pushBottom(st,a);
    }
}
int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(6);
    st.push(4);
    st.print();
    reverseStack(st);
    st.print();
    return 0;
}

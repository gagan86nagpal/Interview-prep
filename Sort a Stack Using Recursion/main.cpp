#include <iostream>

using namespace std;
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
    int getTop()
    {
        return a[top];
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
void sortedInsert(Stack & st,int x)
{
    if(!st.isEmpty() && st.getTop() > x)
    {
        int a= st.pop();
        sortedInsert(st,x);
        st.push(a);
    }
    else
    {
        st.push(x);
    }
}
void sortStack(Stack &st)
{
    if(!st.isEmpty())
    {
        int x = st.pop();
        sortStack(st);
        sortedInsert(st,x);
    }
}
int main()
{
    Stack st;
    st.push(30);
    st.push(-5);
    st.push(18);
    st.push(14);
    st.push(-3);
    st.print();
    sortStack(st);
    st.print();
    return 0;
}

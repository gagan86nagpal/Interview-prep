#include <iostream>

using namespace std;
class Stack{
private:
    int top=-1;
    static const int max=1000;
    int a[1000];
    int minElement;
public:
    void push(int c)
    {
        if(isEmpty())
        {
            a[++top]=c;
            minElement=c;
        }
        else
        {
            if(c>getTop())
            {
                a[++top]=c;
            }
            else
            {
                a[++top]=2*c-minElement;
                minElement=c;
                //cout<<"is pushed :"<<a[top]<<" "<<"rather than"<<c<<"\n";
            }
        }
    }
    int pop()
    {
        if(isEmpty())
        {
            cout<<"Stack is empty\n";
            return 404;
        }
        if(a[top] >minElement)
        {
            return a[top--];
        }
        else
        {
            int ret = minElement;
            minElement=2*minElement-a[top];
            top--;
            return ret;
        }
    }
    bool isEmpty()
    {
        return top==-1;
    }
    bool isFull()
    {
        return top==max-1;
    }
    int getTop()
    {
        int temp = pop();
        push(temp);
        return temp;
    }
    int getmin()
    {
        return minElement;
    }
    void print()
    {
        int temp=top;
        cout<<"Stack(encrypted): ";
        while(temp>=0)
            cout<<a[temp--]<<" ";
        cout<<"\n";
    }
    void printInfo()
    {
        if(!isEmpty())
            cout<<"top:"<<getTop()<<", min:"<<getmin()<<"\n";
        else
            cout<<"Stack is empty\n";
    }
};
int main()
{
    Stack st;
    st.push(10);
    st.printInfo();
    st.push(4);
    st.printInfo();
    st.push(2);
    st.printInfo();
    st.push(5);
    st.printInfo();
    st.push(0);
    st.printInfo();
    st.pop();
    st.printInfo();
    st.pop();
    st.printInfo();
    st.pop();
    st.printInfo();
    st.pop();
    st.printInfo();
    st.pop();
    st.printInfo();
    return 0;
}

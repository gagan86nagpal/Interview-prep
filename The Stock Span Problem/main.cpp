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
int input[100002];
int output[100002];
void StockSpan(int n)
{
    Stack st;
    int i;
    int cnt;
    for(i=0;i<n;i++)
    {
        cnt=1;
        if(i==0)
        {
            output[i]=1;
            st.push(i);
            continue;
        }
        while(!st.isEmpty()&&input[st.getTop()]<input[i])
        {
            cnt+=output[st.pop()];
        }
        output[i]=cnt;
        st.push(i);
    }
}
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>input[i];
    StockSpan(n);
    for(i=0;i<n;i++)
        cout<<output[i]<<" ";
    cout<<"\n";
    return 0;
}

#include <iostream>
#include <utility>
using namespace std;
class Stack{
private:
    int top=-1;
    static const int max=1000;
    pair<int,int> a[1000];
public:
    void push(int c)
    {
        if(isEmpty())
        {
            ++top;
            a[top]=make_pair(c,c);
        }
        else
        {
            ++top;
            a[top]=make_pair(c,min(c,a[top-1].second));
        }
    }
    int pop()
    {
        return a[top--].first;
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
        return a[top].first;
    }
    int getmin()
    {
        return a[top].second;
    }
    void print()
    {
        int temp=top;
        cout<<"Stack: ";
        while(temp>=0)
            cout<<a[temp--].first<<" ";
        cout<<"\n";
    }
};
int main()
{
   Stack st;
   st.push(18);
   st.push(19);
   st.push(29);
   st.push(15);
   st.push(16);
   cout<<st.pop()<<", "<<st.getmin()<<"\n";   // first min is called and then pop
   cout<<st.pop()<<", "<<st.getmin()<<"\n";
   cout<<st.pop()<<", "<<st.getmin()<<"\n";

    return 0;
}

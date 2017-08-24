#include <iostream>
#include <string>
using namespace std;
class stack{
private:
    int top=-1;
    static const int max=1000;
    char a[1000];
public:
    void push(char c)
    {
        a[++top]=c;
    }
    char pop()
    {
        return a[top--];
    }
    bool isEmpty()
    {
        return top==-1;
    }
};
int main()
{
    string s;
    stack st;
    cin>>s;
    for(char c :s)
    {
        st.push(c);
    }
    string rev="";
    while(!st.isEmpty())
    {
        rev+=st.pop();
    }
    cout<<"Reverse String is: "<<rev<<"\n";
    return 0;
}

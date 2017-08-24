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
    char getTop()
    {
        return a[top];
    }
};

bool isOpeningBracket(char c)
{
    return c=='('||c=='['||c=='{';
}
bool isClosingBracket(char c)
{
    return c==')'||c==']'||c=='}';
}
bool match(char a,char b)
{
    return( (a=='('&&b==')' ) || (a=='{'&&b=='}' ) || (a=='['&&b==']' ) );
}
int main()
{
    string input;
    stack st;
    bool flag = true;
    cin>>input;
    for(char c :input)
    {
        if(isOpeningBracket(c))
        {
            st.push(c);
        }
        else if(isClosingBracket(c))
        {
            if(!st.isEmpty() && match(st.getTop(),c))
            {
                st.pop();
            }
            else
            {
                flag=false;
                break;
            }
        }
        else
        {
            flag=false;
        }
    }
    if(flag && st.isEmpty())
        cout<<"Balanced\n";
    else
        cout<<"Not Balanced\n";
    return 0;
}

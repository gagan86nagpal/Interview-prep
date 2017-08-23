#include <iostream>
#include <string>
using namespace std;
struct Stack
{
    char data;
    Stack* down;
};
bool isEmpty(Stack * top)
{
    return top==NULL;
}
char getTop(Stack * top)
{
    int ret=-1;
    if(top==NULL)
        cout<<"UnderFlow\n";
    else
        ret=top->data;
    return ret;
}
// usage similar to call by reference
char pop(Stack* &top)  // reference is passed as to change the local top in the main function
{
    int ret=-1;
    if(top==NULL)
        cout<<"UnderFlow\n";
    else
    {
        ret=top->data;
        Stack* temp = top;
        top=top->down;
        delete temp;
    }
    return ret;
}
// call by reference
void push(Stack* & top,char x)
{
    Stack * temp =new Stack();
    temp->data = x;
    temp->down=top;
    top=temp;
}
void printStack(Stack* top)  // since top should not get changed
{
    cout<<"Stack ";
    if(top==NULL)
        cout<<"is Empty";
    while(top!=NULL)
    {
        cout<<top->data<<" ";
        top=top->down;
    }
    cout<<"\n";
}
int getPrecedence(char c)
{
    if(c=='+'||c=='-')
        return 1;
    if(c=='/'||c=='*')
        return 2;
    if(c=='^')
        return 3;
    else   // c is not an operator
        return -1;
}
bool isOperator(char c)
{
    return (c=='+'||c=='-'||c=='*'||c=='/'||c=='^');
}
int main()
{
    Stack *s=NULL;
    string input;
    cout<<"input: ";
    cin>>input;
    cout<<"ouput: ";
    for(char c: input)
    {
        if(isalpha(c))  // operand
            cout<<c<<" ";
        else if(c==' ')
            continue;
        else if(isOperator(c))
        {
            if(isEmpty(s) || getPrecedence(c)>=getPrecedence(getTop(s)))
            {
                push(s,c);
            }
            else
            {
                cout<<pop(s)<<" ";
                push(s,c);
            }
        }
        else if(c=='(')
            push(s,c);
        else if(c==')')
        {
            while(getTop(s)!='(')
            {
                cout<<getTop(s)<<" ";
                pop(s);
            }
            pop(s);
        }
        else
            cout<<"Wrong Input at:"<<c<<"\n";
    }
    while(!isEmpty(s))
        cout<<pop(s)<<" ";
    return 0;
}

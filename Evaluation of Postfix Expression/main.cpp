#include <iostream>
#include <string>
using namespace std;
struct Stack
{
    double  data;
    Stack* down;
};
bool isEmpty(Stack * top)
{
    return top==NULL;
}
double  applyOperator(double a,double b,char c)
{
    if(c=='+')
        return a+b;
    if(c=='-')
        return a-b;
    if(c=='*')
        return a*b;
    if(c=='/')
        return a/(double )b;
}
double getTop(Stack * top)
{
    double ret=-1;
    if(top==NULL)
        cout<<"UnderFlow\n";
    else
        ret=top->data;
    return ret;
}
// usage similar to call by reference
void pop(Stack* &top)  // reference is passed as to change the local top in the main function
{
    if(top==NULL)
        cout<<"UnderFlow\n";
    else
    {
        Stack* temp = top;
        top=top->down;
        delete temp;
    }
}
// call by reference
void push(Stack* & top,long x)
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
bool isOperator(char c)
{
    return (c=='+'||c=='-'||c=='*'||c=='/');
}
int main()
{

    Stack * s=NULL;
    int i;
    string input;
    char c;
    getline(cin,input);
    double num=0;
    for(i=0;i< (int)input.size();i++)
    {
        c=input[i];
        if(c==' ')
            continue;
        else if(isdigit(c))
        {
            while(i<(int)input.size()&&isdigit(c))
            {
                num=num*10;
                num+=c-'0';
                i++;
                c=input[i];
            }
            i--;
            push(s,num);
            num=0;
        }
        else if(isOperator(c))
        {
            double a,b;
            b=getTop(s);
            pop(s);
            a=getTop(s);
            pop(s);
            push(s,applyOperator(a,b,c));
        }
        else
            cout<<"Wrong input\n";
    }
    cout<<"Answer: "<<getTop(s)<<"\n";
    return 0;
}

#include <iostream>

using namespace std;
struct Stack
{
    int data;
    Stack* down;
};
int getTop(Stack * top)
{
    int ret=-1;
    if(top==NULL)
        cout<<"UnderFlow\n";
    else
        ret=top->data;
    return ret;
}
int pop(Stack* &top)  // reference is passed as to change the local top in the main function
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
void push(Stack* & top,int x)
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
int main()
{
    Stack *s=NULL;  //  s always points to top
    push(s,1);
    push(s,2);
    push(s,4);
    printStack(s);
    cout<<pop(s)<<"\n";
    push(s,5);
    printStack(s);
    return 0;
}

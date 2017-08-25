#include <iostream>

using namespace std;
struct node
{
    int data;
    node *next,*prev;
};
class Stack
{
private:

    node * top=NULL;
    node * middle=NULL;
    int numberOfNodes=0;
public:

    int getTop()
    {
        if(top)
            return top->data;
        else
            return 2147483647;
    }
    void push(int x)
    {
        node * temp = new node();
        temp->data = x;
        temp->next = NULL;
        if(top==NULL)
        {
            top=temp;
            top->prev=NULL;
            middle=top;
        }
        else
        {
            temp->prev=top;
            top->next=temp;
            if(numberOfNodes%2==0)  // even
            {
                middle=middle->next;
            }
            top=temp;
        }
        numberOfNodes++;
    }
    int pop()
    {
        int ret=2147483647;
        if(numberOfNodes==0) // Linked List is empty
        {
            cout<<"Stack is Empty\n";
        }
        else
        {
            node * temp = top;
            ret=top->data;
            top=top->prev;
            delete temp;
            if(top)
                top->next=NULL;
            numberOfNodes--;
            if(numberOfNodes%2==1)
            {
                middle=middle->prev;
            }
        }
        return ret;
    }
    int findMiddle()
    {
        return middle->data;
    }
    void deleteMiddle()
    {
        if(numberOfNodes==0)
        {
            cout<<"Cannot delete Middle as Stack is empty\n";
        }
        else if(numberOfNodes==1)
        {
            delete top;
            top=NULL;
            middle=NULL;

        }
        else if(numberOfNodes==2)
        {
            node * temp = middle;
            middle = middle->next;
            middle->prev=NULL;
            delete temp;
        }
        else if(numberOfNodes%2==1) // odd
        {
            node * temp = middle;
            middle->prev->next=temp->next;
            middle->next->prev=temp->prev;
            middle=middle->prev;
            delete temp;
        }
        else // even
        {
            node * temp = middle;
            middle->prev->next=temp->next;
            middle->next->prev=temp->prev;
            middle=middle->next;
            delete temp;
        }
        if(numberOfNodes!=0)
            numberOfNodes--;
    }
    bool isEmpty()
    {
        return top==NULL;
    }
    void traverse()
    {
        node * temp=top;
        while(temp!=NULL)
        {
            cout<<temp->data;
            if(temp->prev!=NULL)
                cout<<" -> ";
            temp=temp->prev;
        }
        cout<<"\n";
    }
    void printInfo()
    {
        if(!isEmpty())
            cout<<"top:"<<getTop()<<" ,middle:"<<findMiddle()<<"\n";
        else
            cout<<"Stack is Empty\n";
        traverse();
    }
};
int main()
{
    Stack st;
    st.push(1);
    st.printInfo();
     st.push(2);
    st.printInfo();
     st.push(3);
    st.printInfo();
     st.push(4);
    st.printInfo();
     st.push(5);
    st.printInfo();


    st.deleteMiddle();
    st.printInfo();
    st.deleteMiddle();
    st.printInfo();
    st.deleteMiddle();
    st.printInfo();
    st.deleteMiddle();
    st.printInfo();
    st.pop();
    st.printInfo();

    return 0;
}

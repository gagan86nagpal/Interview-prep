#include <iostream>

using namespace std;
struct node
{
    int data;
    node * prev;
    node * next;
};
class Deque
{
    node * f=NULL;
    node * l=NULL;
public:
    int getFront()
    {
        if(f)
            return f->data;
        else
            cout<<"Deque is empty\n";
    }
    int getLast()
    {
        if(l)
            return l->data;
        else
            cout<<"Deque is empty\n";
    }
    void insertLast(int x)
    {
        node * temp = new node();
        temp->data=x;
        temp->next=NULL;
        temp->prev=NULL;
        if(l==NULL) // list is empty
            l=f=temp;
        else
        {
            l->next=temp;
            temp->prev=l;
            l=temp;
        }
    }
    void insertFront(int x)
    {
        node * temp = new node();
        temp->data=x;
        temp->next=NULL;
        temp->prev=NULL;
        if(f==NULL)
            l=f=temp;
        else
        {
            temp->next=f;
            f->prev=temp;
            f=temp;
        }
    }
    void deleteFront()
    {
        node* temp =f;
        if(temp)
        {
            f=f->next;
            delete temp;
            if(f==NULL)  // Now List is empty
                l=NULL;
            else
                f->prev=NULL;
        }
        else
            cout<<"Queue is Empty\n";
    }
    void deleteLast()
    {
        node* temp =l;
        if(temp)
        {
            l=l->prev;
            delete temp;
            if(l==NULL)  // Now List is empty
                f=NULL;
            else
                l->next=NULL;
        }
        else
            cout<<"Queue is Empty\n";
    }
    void print()
    {
        cout<<"Deque Status:";
        node *temp = f;
        if(f)
            cout<<"Front:"<<f->data<<", Rear:"<<l->data<<"\n";
        else
            cout<<"Empty";
        while(temp)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<"\n";
    }
    bool isEmpty()
    {
        return f==NULL;
    }
    bool isFull()   // Linked list never gets full
    {
        return false;
    }
};
int input[1000];
int main()
{
    int n,k;
    cin>>n;
    int a,b;
    int i;
    for(i=0;i<n;i++)
        cin>>input[i];
    cin>>k;
    Deque mi,ma;
    for(i=0;i<k;i++)
    {
        while(!mi.isEmpty()&& input[i]<=input[mi.getLast()])
            mi.deleteLast();
        mi.insertLast(i);

        while(!ma.isEmpty()&& input[i]>=input[ma.getLast()])
            ma.deleteLast();
        ma.insertLast(i);

    }
    cout<<"min\tmax\n";
    for(i=k;i<n;i++)
    {
        a=input[mi.getFront()];
        if(!mi.isEmpty() && mi.getFront()<=i-k)
            mi.deleteFront();
         while(!mi.isEmpty()&& input[i]<=input[mi.getLast()])
            mi.deleteLast();
        mi.insertLast(i);


        b=input[ma.getFront()];
        if(!ma.isEmpty() && ma.getFront()<=i-k)
            ma.deleteFront();
         while(!ma.isEmpty()&& input[i]>=input[ma.getLast()])
            ma.deleteLast();
        ma.insertLast(i);
        cout<<a<<"\t"<<b<<"\n";
       // cout<<a+b<<" ";
    }
    a=input[mi.getFront()];
    b=input[ma.getFront()];
    cout<<a<<"\t"<<b<<"\n";
   // cout<<input[mi.getFront()]+input[ma.getFront()]<<" \n";
    return 0;
}

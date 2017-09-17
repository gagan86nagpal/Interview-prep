#include <iostream>

using namespace std;
struct node
{
    int data;
    node* dif;
};
class LinkedList
{
private :
    node* head;
    node* tail;
public:
    LinkedList()
    {
        tail=NULL;
        head=NULL;
    }
    void insertAtBeginning(int data)
    {
        if(head==NULL)
        {
            head=new node();
            head->data=data;
            head->dif=NULL;
            tail=head;
            return ;
        }
        node* temp = new node();
        temp->data=data;
        temp->dif=head;
        head->dif= (node*) ( ((int)head->dif)^((int)temp)   );
        head=temp;
    }
    void append(int data)
    {
        if(tail==NULL)
        {
            insertAtBeginning(data);
            return;
        }
        node* temp = new node();
        temp->data=data;
        tail->dif=  (node*)((int)tail->dif ^ (int)temp );
        temp->dif=tail;
        tail=temp;
    }
    node* getNeighbour(node* temp,node* prev_temp=NULL)
    {
        return (node *) ( (int)temp->dif ^ (int)prev_temp );
    }

    void printForward()
    {
        node* prev_temp=NULL;
        node* temp= head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            node * temp_next=getNeighbour(temp,prev_temp);
            prev_temp=temp;
            temp=temp_next;
            if(temp!=NULL)
                cout<<" - > ";
        }
        cout<<"\n";
    }
    void printBackward()
    {
        node* prev_temp=NULL;
        node* temp= tail;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            node * temp_next=getNeighbour(temp,prev_temp);
            prev_temp=temp;
            temp=temp_next;
            if(temp!=NULL)
                cout<<" - > ";
        }
        cout<<"\n";
    }
};
int main()
{
    LinkedList ll ;
    ll.insertAtBeginning(2);
    ll.insertAtBeginning(3);
    ll.insertAtBeginning(4);
    ll.insertAtBeginning(5);
    ll.printForward();
    ll.append(6);
    ll.printForward();
    ll.printBackward();
    return 0;
}

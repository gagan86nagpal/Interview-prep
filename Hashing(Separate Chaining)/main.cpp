#include <iostream>

using namespace std;
struct node
{
    int data;
    node* next;
};
class LinkedList
{
private:
    node* head=NULL;
public:
    node* getNewNode(int data)
    {
        node* temp = new node();
        temp->data=data;
        temp->next=NULL;
        return temp;
    }
    void appendList(int data)
    {
        if(head==NULL)
        {
            head=getNewNode(data);
            return;
        }
        node* temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=getNewNode(data);
    }
    void printList()
    {
        node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            if(temp->next)
                cout<<" -> ";
            temp=temp->next;
        }
        cout<<"\n";
    }
    void deleteList(int data)
    {
        cout<<data<<" : ";
        if(head==NULL)
            cout<<"does not exists\n";
        node* temp=head;
        if(head->data==data)
        {
            head=head->next;
            delete temp;
            return;
        }
        while(temp->next!=NULL)
        {
            if(temp->next->data==data)
                break;
            temp=temp->next;
        }
        if(temp->next==NULL)
            cout<<"does not exists\n";
        else
        {
            node * temp2 = temp->next;
            temp->next=temp2->next;
            delete temp2;
            cout<<"is deleted\n";
        }
    }
    void searchList(int data)
    {
        node* temp=head;
        while(temp!=NULL)
        {
            if(temp->data==data)
                break;
            temp=temp->next;
        }
        if(temp==NULL)
            cout<<"Not Exists\n";
        else
            cout<<"Found\n";
    }
};
class hashTable
{
private:
    LinkedList table[23];
public:
    int hashFunction(int n)
    {
        return n%23;
    }
    void deleteHashTable(int data)
    {
        int key = hashFunction(data);
        table[key].deleteList(data);
    }
    void printKey(int key)
    {
        cout<<key<<" : ";
        table[key].printList();
    }

    void searchHashTable(int data)
    {
        int key = hashFunction(data);
        cout<<data<<" : ";
        table[key].searchList(data);
    }
    void insertHashTable(int data)
    {
        int key=hashFunction(data);
        table[key].appendList(data);
    }

};
int main()
{
    hashTable h;
    int i;
    for(i=1;i<=50;i++)
        h.insertHashTable(i);
    h.printKey(4);
    h.deleteHashTable(50); // 50 is deleted
    h.printKey(4);
    h.searchHashTable(50);
    h.searchHashTable(34);
    h.printKey(11);
    h.deleteHashTable(34);
    h.printKey(11);
    return 0;
}

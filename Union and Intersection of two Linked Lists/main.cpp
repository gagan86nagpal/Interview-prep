#include <iostream>

using namespace std;
/*
Given two Linked Lists, create union and intersection lists that contain union and intersection
of the elements present in the given lists. Order of elements in output lists does not matter.
*/
//using hashing with separate chaining

// Time is linear if hashing APi supports linear insert and search

struct node
{
    int data;
    node* next;
};
class LinkedList
{
public:
    node* head=NULL;  // too lazy to create an iterator
    node* getNewNode(int data)
    {
        node* temp = new node();
        temp->data=data;
        temp->next=NULL;
        return temp;
    }
    void appendList(int data)
    {
        if(searchList(data)) // if already present , then do not insert
            return;
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
    bool searchList(int data)
    {
        node* temp=head;
        while(temp!=NULL)
        {
            if(temp->data==data)
                break;
            temp=temp->next;
        }
        if(temp==NULL)
            return false;
        else
            return true;
    }
};
class hashTable
{
public:
    static const int mod=23;
    LinkedList table[mod];
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

    bool searchHashTable(int data)
    {
        int key = hashFunction(data);
        return table[key].searchList(data);
    }
    void insertHashTable(int data)
    {
        int key=hashFunction(data);
        table[key].appendList(data);
    }
    void fillHashTableByLinkedList(LinkedList l)
    {
        node* head=l.head;
        while(head!=NULL)
        {
            insertHashTable(head->data);
            head=head->next;
        }
    }

};
LinkedList intersectionLL(hashTable &h1,hashTable &h2) // passed by reference to avoid copying the whole hash table
{
    LinkedList ret;
    int mod=h2.mod;
    int i;
    node* head;
    for(i=0;i<mod;i++)
    {
        head=h2.table[i].head;
        while(head!=NULL)
        {
            if(h1.searchHashTable(head->data))
                ret.appendList(head->data);
            head=head->next;
        }
    }
    return ret;
}
LinkedList unionLL(hashTable &h1,hashTable &h2) // passed by reference to avoid copying the whole hash table
{
    int mod=h2.mod;
    int i;
    node* head;
    LinkedList ret;
    // taking all elements of h2
    for(i=0;i<mod;i++)
    {
        head=h2.table[i].head;
        while(head!=NULL)
        {
            ret.appendList(head->data);
            head=head->next;
        }
    }
    mod=h1.mod;
    // only those elements of h1 not in h2
    for(i=0;i<mod;i++)
    {
        head=h1.table[i].head;
        while(head!=NULL)
        {
            if(!h2.searchHashTable(head->data))
                ret.appendList(head->data);
            head=head->next;
        }
    }
    return ret;
}
int main()
{
    LinkedList l1,l2;

    l1.appendList(20);
    l1.appendList(4);
    l1.appendList(15);
    l1.appendList(10);

    l2.appendList(10);
    l2.appendList(2);
    l2.appendList(4);
    l2.appendList(8);

    cout<<"l1:";
    l1.printList();
    cout<<"l2:";
    l2.printList();
    hashTable h1,h2;

    h1.fillHashTableByLinkedList(l1);
    h2.fillHashTableByLinkedList(l2);

    cout<<"Intersection:";
    LinkedList intersectionList = intersectionLL(h1,h2);
    intersectionList.printList();

    cout<<"Union\t    :";
    LinkedList unionList = unionLL(h1,h2);
    unionList.printList();
    return 0;
}

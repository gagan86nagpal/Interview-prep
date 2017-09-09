#include <iostream>

using namespace std;
/*
Given two arrays: arr1[0..m-1] and arr2[0..n-1]. Find whether arr2[] is a subset of arr1[] or not.
Both the arrays are not in sorted order. It may be assumed that elements in both array are distinct.
*/


/*
Insert Bigger array elements in hashtable.
For each element in small array ,check if it is hashtable or not.
if element should exists ,
    return true
else
    return false
*/

// Using hashing by separate chaining
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

};
int main()
{
    hashTable h;
    int arr1[] = {11, 1, 13, 21, 3, 7};
    int arr2[] = {11, 3, 7, 1};

    int m = sizeof(arr1)/sizeof(arr1[0]);
    int n = sizeof(arr2)/sizeof(arr2[0]);

    // if arr2 is a subset of arr1 or not
    int i;
    for(i=0;i<m;i++)
        h.insertHashTable(arr1[i]);
    bool flag=true;
    for(i=0;i<n;i++)
    {
        if(!h.searchHashTable(arr2[i]))
        {
            flag=false;
            break;
        }
    }
    if(flag)
        cout<<"arr2 is a subset of arr1";
    else
        cout<<"arr2 is not a subset of arr1";
    return 0;
}

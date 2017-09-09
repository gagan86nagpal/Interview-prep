#include <iostream>

using namespace std;
class hashtable
{
private:
    static const int cap=20;
    int h[cap]; // size should be greater than the total number of entries in hashtable
    bool isdeleted[cap]; // same size as that of hash table
public:
    hashtable()
    {
        int i;
        for(i=0;i<cap;i++)
        {
            h[i]=-1;
            isdeleted[i]=false;
        }
    }
    int hashFunction(int data)
    {
        return data%23;
    }
    void insertData(int data)
    {
        int key = hashFunction(data);
        while(h[key]!=-1 && isdeleted[key]==false)
        {
            key++;   // linear probing
            key%=cap;
        }
        h[key]=data;
        isdeleted[key]=false;
    }
    void deleteData(int data)
    {
        int key = hashFunction(data);
        while(h[key]!=data && h[key]!=-1)
        {
            key++;   // linear probing
            key%=cap;
        }
        if(h[key]==-1)
            cout<<data<<" : does not exists\n";
        else
        {
            isdeleted[key]=true;
            cout<<data<<" : is deleted\n";
        }
    }
    void searchData(int data)
    {
        int key = hashFunction(data);
        while(h[key]!=data && h[key]!=-1)
        {
            key++;   // linear probing
            key%=cap;
        }
        if(h[key]==-1)
            cout<<data<<" : does not exists\n";
        else
            cout<<data<<" : exists\n";
    }
};
int main()
{
    hashtable h;
    h.insertData(30);
    h.insertData(8);
    h.insertData(7);
    h.deleteData(8);
    h.searchData(7);
    return 0;
}

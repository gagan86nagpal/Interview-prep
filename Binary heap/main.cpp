#include <iostream>
#include <limits.h>

using namespace std;
class MinHeap
{
private:
    int *a;
    int capacity;
    int heap_size;
    int left(int i);
    void heapify(int i);
    int right(int i);
    int parent(int i);
public:
    MinHeap(int cap);
    int getMin();
    int extractMin();
    void decreaseKey(int i,int val);
    void insertKey(int val);
    void deleteIndex(int i);
    void debug();

};
    MinHeap:: MinHeap(int cap)
    {
        capacity=cap;
        heap_size=0;
        a=new int[cap];
    }
    int MinHeap:: left(int i)
    {
        return (i<<1)+1;
    }
    int MinHeap::right(int i)
    {
        return (i<<1)+2;
    }
    int MinHeap::parent(int i)
    {
        return (i-1)>>1;
    }
    int MinHeap::getMin()
    {
        return a[0];
    }
    // If node's is larger than it's child
    //move node down  to appropriate place
    void MinHeap::heapify(int i)
    {
        int l,r,temp;
        l=left(i);
        r=right(i);
        int small=i;
        if(a[l]<a[small] && l<heap_size)
            small=l;
        if(a[r]<a[small]&& r<heap_size)
            small=r;
        if(small!=i)
        {
            temp=a[small];
            a[small]=a[i];
            a[i]=temp;
            heapify(small);
        }
    }
    void MinHeap::decreaseKey(int i,int key)
    {
        if(a[i]<key) // Key present is lower than new value of key
            return ;
        a[i]=key;
        int temp;
        while(i!=0 && a[i]<a[parent(i)])
        {
            temp=a[i];
            a[i]=a[parent(i)];
            a[parent(i)]=temp;
            i=parent(i);
        }
    }
    void MinHeap::insertKey(int val)
    {
        if(heap_size==capacity-1)// already full
        {
            cout<<"heap is full\n";
            return ;
        }
        int temp;
        a[heap_size]=val;
        heap_size++;
        int i=heap_size-1;
        while(i!=0 && a[i]<a[parent(i)])
        {
            temp=a[i];
            a[i]=a[parent(i)];
            a[parent(i)]=temp;
            i=parent(i);
        }
    }
    void MinHeap:: deleteIndex(int i)
    {
       a[i]=a[heap_size-1];
       heap_size--;
       heapify(i);
    }

    int MinHeap::extractMin()
    {
        int temp = a[0];
        deleteIndex(0);
        return temp;
    }
    void MinHeap::debug()
    {
        int i;
        cout<<"heap:";
        for(i=0;i<heap_size;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<"\nheap_size:"<<heap_size<<"\n";
    }
int main()
{
    MinHeap h(11);
    h.insertKey(3);
    h.insertKey(2);
    h.deleteIndex(1);
    h.insertKey(15);
    h.insertKey(5);
    h.insertKey(4);
    h.deleteIndex(1);
    h.insertKey(53);
    h.insertKey(42);
    h.insertKey(12);
    h.insertKey(1);
    h.debug();
    cout << h.extractMin() << " \n";
    h.debug();
    cout << h.getMin() << " ";
    h.decreaseKey(2, 1);
    cout << h.getMin();
    return 0;
}

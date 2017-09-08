#include <iostream>

using namespace std;

// Make a heap oh k+1 elemnets
// Extract Min from it , and push the next element
// do this will we have reached end of input
// Now ExtractMin , till the heap gets empty

// time is O(k + (n)*log(k) )
void heapify(int a[],int n,int i)
{
    int l = 2*i+1,r=2*i+2,small=i;
    if(l<n && a[small] > a[l])
        small=l;
    if(r<n && a[small] > a[r])
        small=r;
    if(i!=small)
    {
        swap(a[i],a[small]);
        heapify(a,n,small);
    }
}
int extractMin(int heap[],int &heap_size)
{
    int temp =  heap[0];
    heap[0]=heap[heap_size-1];
    heap_size--;
    heapify(heap,heap_size,0);
    return temp;
}
void print(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}
void KSort(int a[],int n,int k)
{
    int heap[100];
    int i;
    // 0th element in sorted array  may be at k+1 index
    for(i=0;i<=k;i++)
        heap[i]=a[i];
    // build heap
    int heap_size=k+1;
    for(i=heap_size/2;i>=0;i--)
        heapify(heap,heap_size,i);
    for(i=k+1;i<n;i++)
    {
        a[i-k-1]=heap[0];
        heap[0]=a[i];
        heapify(heap,heap_size,0);
    }
    i-=k+1;
    while(heap_size>0)
        a[i++]=extractMin(heap,heap_size);
}
int main()
{
    int k = 3;
    int arr[] = {2, 6, 3, 12, 56, 8};
    int n = sizeof(arr)/sizeof(arr[0]);
    KSort(arr, n, k);
    print(arr,n);
    return 0;
}

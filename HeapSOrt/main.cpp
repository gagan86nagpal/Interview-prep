#include <iostream>

using namespace std;

// assumes that children of ith nodes are already min heap
// So, it makes a node go down at appropriate place
void heapify(int a[],int i,int n )
{
    int l=2*i+1,r=2*i+2,small=i;

    if(l<n && a[small]>a[l])
        small=l;
    if(r<n &&a[small]>a[r])
        small=r;
    if(small!=i)
    {
        swap(a[small],a[i]);
        heapify(a,small,n);
    }
}
void print(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}

// we are using a Min heap , so last element is always minimum giving us a descending order sorting
// MaxHeap would have given us an ascending order sorting
void heapSort(int a[], int n)
{
    int i;
    for(i=n/2 ;i >=0;i--) // build the heap in linear time
        heapify(a,i,n);
    for(i=0;i<n;i++)
    {
        swap(a[0],a[n-1-i]); // it makes the last element as smallest and also last element which was part of array as the root of heap
        heapify(a,0,n-1-i); // This heapify the first node as it gets altered by previous statement also decrease the size in every iteration
    }
}
int main()
{
    int a[]={2,6,3,1,7,8,5,4,9,4,1,1,34,1,34,1};
    int n= sizeof(a)/sizeof(a[0]);
    print(a,n);
    heapSort(a,n);
    print(a,n);
    return 0;
}

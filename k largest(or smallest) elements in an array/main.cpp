#include <iostream>

using namespace std;
// Idea is to make a min/max heap of first k elements i.e. a[0..k-1]
// Now for each element x in arr[k..n] , if  x is greater than smallest element in heap then delete smallest , and insert x

void heapify(int a[],int i,int n)
{
    int l=2*i+1,r=2*i+2,small=i;
    if(l<n&&a[small] > a[l])
        small=l;
    if(r<n&&a[small] > a[r])
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
void KLargest(int a[],int n ,int k)
{
    int temp[100];
    int i;
    for(i=0;i<k;i++)
        temp[i]=a[i];


    // build minHeap out of temp array
    for(i=k/2;i>=0;i--)
    {
        heapify(temp,i,k); // size of temp is k
    }
    // for rest of the elements
    for(i=k;i<n;i++)
    {
        // any element is greater than min
        if(temp[0] < a[i])
        {
            temp[0]=a[i];   // delete minimum element
            heapify(temp,0,k); // adjust the heap
        }
    }
    cout<<k<<" largest:";
    print(temp,k);

}
int main()
{
    int a[]={1, 23, 12, 9, 30, 2, 50, 12, 41};
    int n  =sizeof(a)/sizeof(a[0]);
    int k = 3;
    KLargest(a,n,k);
    k=4;
    KLargest(a,n,k);
    k=1;
    KLargest(a,n,k);
    return 0;
}

// Time is O(k + (n-k)*log(k)  )

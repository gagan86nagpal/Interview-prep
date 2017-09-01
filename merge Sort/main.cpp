#include <iostream>

using namespace std;
void print(int[],int);
void swap1(int& a , int& b)
{
    int t=a;
    a=b;
    b=t;
}
void merging(int a[],int lo,int mid,int hi)
{
    int b[100];
    int i=lo,j=mid+1,k=0;
    while(i<=mid && j<=hi)
    {
        if(a[i]>a[j])
            b[k++]=a[j++];
        else
            b[k++]=a[i++];
    }
    while(i<=mid)
        b[k++]=a[i++];
    while(j<=hi)
        b[k++]=a[j++];
    for(i=0;i<k;i++)
        a[lo+i]=b[i];
}
void mergeSort(int a[],int lo,int hi)
{
    if(lo<hi)
    {
        int mid=(lo+hi)/2;
        mergeSort(a,lo,mid);
        mergeSort(a,mid+1,hi);
        merging(a,lo,mid,hi);
    }
}

void print(int a[],int n )
{
    int i;
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}
int main()
{
    int a[]={2,5,3,1,4,9,7,6,8,10};
    int n=sizeof(a)/sizeof(a[0]);
    print(a,n);
    mergeSort(a,0,n-1);
    print(a,n);
    return 0;
}

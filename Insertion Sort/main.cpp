#include <iostream>

using namespace std;
void print(int[],int);
void swap1(int& a , int& b)
{
    int t=a;
    a=b;
    b=t;
}
void InsertionSort(int a[],int n)
{
    int i,j;
    int temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
         for(j=i-1;j>=0;j--)
        {
            if(a[j]<temp)
                break;
            a[j+1]=a[j];
        }
        a[j+1]=temp;
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
    int a[]={2,4,2,6,7,2,1,6,3,5,2};
    int n=sizeof(a)/sizeof(a[0]);
    print(a,n);
    InsertionSort(a,n);
    print(a,n);
    return 0;
}

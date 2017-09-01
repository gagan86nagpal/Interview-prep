#include <iostream>

using namespace std;
void print(int[],int);
void swap1(int& a , int& b)
{
    int t=a;
    a=b;
    b=t;
}
void selectionSort(int a[],int n)
{
    int i,j;
    int m;
    for(j=0;j<n-1;j++)
    {
         m=0;
         for(i=0;i<n-j;i++)
        {
            if(a[m]<a[i])
                m=i;
        }
        swap1(a[n-1-j],a[m]);
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
    int a[]={4,2,2,2,6,7,2,1};
    int n=sizeof(a)/sizeof(a[0]);
    print(a,n);
    selectionSort(a,n);
    print(a,n);
    return 0;
}

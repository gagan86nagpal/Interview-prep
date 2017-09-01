#include <iostream>

using namespace std;
void print(int[],int);
void swap1(int& a , int& b)
{
    int t=a;
    a=b;
    b=t;
}
void BubbleSort(int a[],int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
         for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
                swap1(a[j],a[j+1]);
        }
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
    int a[]={2,6,7,2,1,6,3,5,2};
    int n=sizeof(a)/sizeof(a[0]);
    print(a,n);
    BubbleSort(a,n);
    print(a,n);
    return 0;
}

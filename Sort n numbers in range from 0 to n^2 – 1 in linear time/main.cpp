#include <iostream>

using namespace std;
int a[1000];
int b[20];
int c[1000];
void countSort(int n,int p)
{
    int ma=10,i;
    for(i=0;i<=ma;i++)
        b[i]=0;
    for(i=0;i<n;i++)
        b[ (a[i]/p)%10 ]++;
    for(i=1;i<=ma;i++)
        b[i]+=b[i-1];
    for(i=n-1;i>=0;i--)
         c[--b[(a[i]/p)%10]]=a[i];
    for(i=0;i<n;i++)
        a[i]=c[i];
}
void print(int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    int ma = a[0];
    for(i=0;i<n;i++)
        ma = max(ma,a[i]);
    int maxp=1;
    while(maxp <=ma)
        maxp*=10;
    int p=1;
    while(p<maxp)
    {
        countSort(n,p);
        //print(n);
        p*=10;
    }
    print(n);
    return 0;
}

#include <iostream>

using namespace std;
int a[1000];
int b[1000];
int c[1000];
void countSort(int n)
{
    int ma=a[0],i;
    for(i=0;i<=ma;i++)
        b[i]=0;
    for(i=0;i<n;i++)
        b[a[i]]++,ma = max(ma,a[i]);
    for(i=1;i<=ma;i++)
        b[i]+=b[i-1];
    for(i=n-1;i>=0;i--)
         c[--b[a[i]]]=a[i];
    for(i=0;i<n;i++)
        a[i]=c[i];
}
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    countSort(n);
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    return 0;
}

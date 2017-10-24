#include <iostream>

using namespace std;
int a[1002];
int upper_bound(int l,int h,int x)
{
    if(x>a[h])
        return h+1;
    if(x<a[l])
        return l;

    int m = (l+h)/2;
    if(a[m]<=x && a[m+1]>x)
        return m+1;
    if(a[m] > x)
        return upper_bound(l,m,x);
    else
        return upper_bound(m+1,h,x);
}
int main()
{
    int n,i,x,k;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    cin>>k>>x;
    int r = upper_bound(0,n-1,x);
 //   cout<<"Upper bound is :"<<a[r]<<"\n";
    int l = r-1;
    while(l>=0 &&a[l]==x)
        l--;
//    cout<<"Lower Bound is :"<<a[l]<<"\n";
    // starting pushing from l and r
    int cnt=0;
    while(l>=0 && r<=n-1 && cnt < k)
    {
        if(x-a[l]<a[r]-x )
            cout<<a[l--]<<" ";
        else
            cout<<a[r++]<<" ";
        cnt++;
    }
    while(cnt<k && l>=0)
    {
        cout<<a[l--]<<" ";
        cnt++;
    }
    while(cnt < k && r<=n-1)
    {
        cout<<a[r++]<<" ";
        cnt++;
    }
    return 0;
}
/*
13
12 16 22 30 35 39 42 45 48 50 53 55 56
4 35
*/

#include <iostream>

using namespace std;
// General idea was to first calculate (n*(n+1) )/2
// And keep on subtracting a[i] from it
// But ,  (n*(n+1) )/2 may overflow , so we fill calculate sum of 1+2+3 .. in each iteration and keep on subtracting
// We don't even need an array as we are doing computation at an iteration which involves only ith index
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,sum;
        cin>>n;
        sum=n;
        for(int i=1;i<=n-1;i++)
        {
            int x;
            cin>>x;
            sum+=i-x;
        }
        cout<<sum<<"\n";
    }
    return 0;
}

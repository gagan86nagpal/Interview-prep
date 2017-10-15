#include <iostream>


// Brute Force
using namespace std;
int get_sum(int x)
{
    int ret=0;
    while(x)
    {
        ret+=x%10;
        x/=10;
    }
    return ret;
}
int main()
{
    int t,ans=0,n,i;
    cin>>t;
    while(t--)
    {
        ans=0;
        cin>>n;
        for(i=0;i<=n;i++)
            ans+=get_sum(i);
        cout<<ans<<"\n";
    }
    return 0;
}

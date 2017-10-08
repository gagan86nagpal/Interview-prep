#include <iostream>

using namespace std;
int a[102];
int dp[102];
void init(int n)
{
    int i;
    for(i=0;i<n;i++)
        dp[i]=-1;
}
int minJumps(int i,int n)
{
    if(i>n)
        return 0;
    if(dp[i]!=-1)
        return dp[i];
    int ma=a[i];
    int ans=1000000;
    int j;
    for(j=1;j<=ma;j++)
        ans=min(minJumps(i+j,n),ans);
    return dp[i]=ans+1;
}
int main()
{
    int n;
    int i;
    cin>>n;
    init(n);
    for(i=0;i<n;i++)
        cin>>a[i];
    int ans=minJumps(0,n-1);
    if(ans<1000001)
        cout<<ans<<"\n";
    else
        cout<<"-1\n";
    return 0;
}

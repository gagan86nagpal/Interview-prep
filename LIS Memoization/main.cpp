#include <iostream>

using namespace std;
int dp[1000][1000];
int toPrint[1000][1000];
int a[1000];
void init(int n)
{
    int i,j;
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            dp[i][j]=-1;
}
void printList(int n)
{
    int i;
    for(i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
            cout<<toPrint[i][j]<<" ";
        cout<<"\n";
    }

}
void printLIS(int n,int l)
{
    int r,c;
    r=1;
    c=0;
    while(l>0)
    {
        if(toPrint[r][c]==1)
        {
            cout<<a[r]<<" ";
            c=r;
            l--;
        }
        r++;
    }
}
int lis(int in,int n,int prev=0)
{
    if(in==n+1)
        return 0;
    if(dp[in][prev]!=-1)
        return dp[in][prev];
    if(a[in] > a[prev])
    {
        int take=1+lis(in+1,n,in);
        int notTake=lis(in+1,n,prev);
        dp[in][n]=max(take,notTake);
        if(dp[in][n]==take)
        {
            toPrint[in][prev]=1;
        }
        else
        {
            toPrint[in][prev]=0;
        }
        return dp[in][n];
    }
    else
    {
        dp[in][n]=lis(in+1,n,prev);
        toPrint[in][prev]=0;
        return dp[in][n];
    }
}
int main()
{
   int n;
   cin>>n;
   init(n);
   a[0]=-1;
   for(int i=1;i<=n;i++)
    cin>>a[i];
    int ans = lis(1,n);
    cout<<"LIS Length:"<<ans<<"\n";;
    printLIS(n,ans);
    return 0;
}

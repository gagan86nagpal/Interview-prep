#include <iostream>

using namespace std;

int a[10000];
int dp[100][1000];
void init(int n,int sum)
{
    int i,j;
    for(i=0;i<=n;i++)
        for(j=0;j<=sum;j++)
            dp[i][j]=-1;
}


bool subsetSum(int in, int n,int sum)
{
    if(sum==0)
        return true;
    if(in==n || sum <0)
        return false;
    if(dp[in][sum]!=-1)
        return dp[in][sum]==1;
    return (dp[in][sum]=  ( subsetSum(in+1,n,sum)||subsetSum(in+1,n,sum-a[in])  )==1  );
}
int main()
{
    int n,i,sum;
    cin>>n>>sum;
    for(i=0;i<n;i++)
        cin>>a[i];
    init(n,sum);
    bool ans= subsetSum(0,n,sum);
    cout<< (ans==1 ?"yes":"no") <<"\n";
    return 0;
}


/*
6 9
3 34 4 12 5 2
*/

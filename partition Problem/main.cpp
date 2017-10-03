#include <iostream>

using namespace std;
int a[100];
int dp[100][100000];
void init(int n,int sum)
{
    int i,j;
    for(i=0;i<=n;i++)
        for(j=0;j<=2*sum;j++)
            dp[i][j]=-1;
}
bool partition(int in,int diff,int sum)
{
    if(in==-1)
        return diff==sum;
    if(dp[in][diff]!=-1)
        return dp[in][diff];
    return (dp[in][diff]= (partition(in-1,diff+a[in],sum) ) || ( partition(in-1,diff-a[in],sum) ) );
}
int main()
{
    int n;
    cin>>n;
    int i,sum=0;
    for(i=0;i<n;i++)
        cin>>a[i],sum+=a[i];
    init(n,sum);
    bool ans=partition(n-1,sum,sum);
    cout<<ans<<"\n";
    return 0;
}

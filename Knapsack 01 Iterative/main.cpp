#include <iostream>
#include <vector>
using namespace std;

// Limited supply of items
vector <int> val;
vector <int> weight;

int dp[1000][1000];

int knapsack(int n, int weightLeft)
{

    int i,j;
    for(i=0;i<=n;i++)
        for(j=0;j<=weightLeft;j++)
            if(j==0)
                dp[i][j]=0;
            else if(i==0)
            {
                if(j>=weight[i])
                    dp[i][j]=val[i];
                else
                    dp[i][j]=0;
            }
            else if(j>=weight[i])
                dp[i][j]=max(val[i]+dp[i-1][j-weight[i]],dp[i-1][j]);
            else
                dp[i][j]=dp[i-1][j];

    return dp[n][weightLeft];

}
int main()
{
    int n;
    int cap;
    cin>>n>>cap;
    int i,x;
    for(i=0;i<n;i++)
    {
        cin>>x;
        val.push_back(x);
    }
    for(i=0;i<n;i++)
    {
        cin>>x;
        weight.push_back(x);
    }
    int ans = knapsack(n-1,cap);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=cap;j++)
            cout<<dp[i][j]<<" ";
        cout<<"\n";
    }
    cout<<ans<<"\n";
    return 0;
}


/*
5 4
8 4 0 5 3
1 2 3 2 2
*/

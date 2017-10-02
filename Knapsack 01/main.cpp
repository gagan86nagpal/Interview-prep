#include <iostream>
#include <vector>
using namespace std;

// Limited supply of items
vector <int> val;
vector <int> weight;

int dp[1000][1000];
void init(int n,int w)
{
    int i,j;
    for(i=0;i<=n;i++)
        for(j=0;j<=w;j++)
            dp[i][j]=-1;
}
int knapsack(int n, int weightLeft)
{
    if(n<0  ||weightLeft<0)
        return 0;
    if(dp[n][weightLeft]!=-1)
        return dp[n][weightLeft];
    if(weightLeft>=weight[n])
        return dp[n][weightLeft]=max (val[n]+knapsack(n-1,weightLeft-weight[n]) , knapsack(n-1,weightLeft) );
    else
        return dp[n][weightLeft]=knapsack(n-1,weightLeft);
}
int main()
{
    int n;
    int cap;
    cin>>n>>cap;
    init(n,cap);
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
    cout<<ans<<"\n";
    return 0;
}


/*
3 50
60 100 120
10 20 30
*/

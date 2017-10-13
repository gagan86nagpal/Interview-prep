#include <iostream>
#include <vector>
using namespace std;
/*
we can also make a 2d grid representing the number pad , and can use dfs to iterate as well
*/
vector < int> keyJumps[10];
long long dp[10][100];
void init(int n)
{
    vector < int> v;
    v=vector <int> {0,8};
    keyJumps[0] =v;
    v = vector<int>{1,2,4};
    keyJumps[1]=v;
    v = vector<int>{1,2,3,5};
    keyJumps[2]=v;
    v = vector<int>{2,3,6};
    keyJumps[3]=v;
    v = vector<int>{1,4,5,7};
    keyJumps[4]=v;
    v = vector<int>{2,4,5,6,8};
    keyJumps[5]=v;
    v = vector<int>{3,5,6,9};
    keyJumps[6]=v;
    v = vector<int>{4,7,8};
    keyJumps[7]=v;
    v = vector<int>{0,5,7,8,9};
    keyJumps[8]=v;
    v = vector<int>{6,8,9};
    keyJumps[9]=v;


    int i,j;
    for(i=0;i<=10;i++)
        for(j=0;j<=n;j++)
            dp[i][j]=-1;
}


long long countNumbers(int button ,int n)
{
    if(n==0)
        return 1ll;
    if(dp[button][n]!=-1)
        return dp[button][n];
    int i;
    long long sum=0;
    for(i=0;i<(int)keyJumps[button].size();i++)
        sum+=countNumbers(keyJumps[button][i],n-1);
    return dp[button][n]=sum;
}

long long solve(int n)
{
    int i;
    long long sum=0;
    for(i=0;i<10;i++)
        sum+=countNumbers(i,n-1);
    return sum;
}
int main()
{
    int n;
    long long ans;
    cin>>n;
    init(n);
    ans=solve(n);
    cout<<ans<<"\n";

    return 0;
}

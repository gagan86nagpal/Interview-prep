#include <iostream>

using namespace std;

/*
Simple recursive solution is to for every digit , we can go digit,digit+1...9 in next digits
do this till we have utilized n digits
*/


// should have used long long
int dp[10][10000];
int countNumbers(int digit,int n)
{

    if(n==0)
        return 1;
    if(dp[digit][n]!=-1)
        return dp[digit][n];
    int i,sum=0;
    for(i=digit;i<=9;i++)
    {
        sum+=countNumbers(i,n-1);
    }
    return dp[digit][n]=sum;
}
void init(int n)
{
    int i,j;
    for(i=0;i<10;i++)
        for(j=0;j<=n;j++)
            dp[i][j]=-1;
}
int main()
{
    int n;
    cin>>n;
    init(n);
    int ans=countNumbers(0,n);
    cout<<ans<<"\n";
    return 0;
}

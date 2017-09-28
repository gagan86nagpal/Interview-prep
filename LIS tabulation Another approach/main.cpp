#include <iostream>

using namespace std;
int dp[1000];
int a[1000];
int lis(int n)
{
    int i,j,ma=-1;
  for (i = 0; i < n; i++ )
    dp[i] = 1;

   for (i = 1; i < n; i++ )
    for (j = 0; j < i; j++ )
        if ( a[i] > a[j] && dp[i] < dp[j] + 1)
            dp[i] = dp[j] + 1;

    for (i = 0; i < n; i++ )
        if (ma < dp[i])
            ma = dp[i];
    return ma;
}
int main()
{
    int n;
   cin>>n;
   for(int i=0;i<n;i++)
    cin>>a[i];
    int ans = lis(n);
    cout<<"LIS Length:"<<ans<<"\n";

    return 0;
}

/*
6
2 5 1 5 2 1
*/

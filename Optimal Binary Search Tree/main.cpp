#include <iostream>

using namespace std;

int dp[1000][1000];
int freq[1000];
int freq_sum[1000];
int keys[1000];

int solve(int n)
{
    int i,j,l,k; // 1 based indexing

    for(i=1;i<=n;i++)
        freq_sum[i]+=freq_sum[i-1]+freq[i];
    for(l=1;l<=n;l++)
    {
        for(i=1;i<=n-l+1;i++)
        {
            j=i+l-1;/
            for(k=i;k<=j;k++)  // choosing k as root
            {
                int val;
                int left_tree= dp[i][k-1] + freq_sum[k-1] - freq_sum[i-1] ;
                int right_tree=dp[k+1][j]  + freq_sum[j] - freq_sum[k];
                val=freq[k] +left_tree+ right_tree;
                if(i==k)
                    dp[i][j]=val;
                else
                    dp[i][j]=min(dp[i][j],val);
            }
        }
    }
    return dp[1][n];

}
int main()
{
    int n;
    int i;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>keys[i];
    for(i=1;i<=n;i++)
        cin>>freq[i];

    int ans=solve(n);
    cout<<ans<<"\n";
    return 0;
}


/*

3
10 12 20
34 8 50
*/

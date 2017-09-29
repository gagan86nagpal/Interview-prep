#include <iostream>
#include <string>
using namespace std;

bool dp[1002][1002];
string a,b,c;
bool tabulation(int n,int m)
{
    int i,j;

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0||j==0)
            {
                if(i==0&&j==0)
                    dp[i][j]=true;
                else if(i==0)
                    dp[i][j]=c[j-1]==b[j-1];
                else
                    dp[i][j]=c[i-1]==a[i-1];
                continue;
            }
            if(c[i+j-1]==a[i-1] && a[i-1]==b[j-1]) // both are matching
                dp[i][j] = dp[i-1][j]||dp[i][j-1];
            else if(c[i+j-1]==a[i-1])
                dp[i][j]=dp[i-1][j];
            else if(c[i+j-1]==b[j-1])
                dp[i][j]=dp[i][j-1];
            else
                dp[i][j]=false; // redundant;
        }
    }
    return dp[n][m];
}
int main()
{
    cin>>a>>b>>c;
    bool ans = tabulation(a.size(),b.size());
    cout<<(ans?"Yes":"No");
/*
    for(int i=0;i<=a.size();i++)
    {
        for(int j=0;j<=b.size();j++)
            cout<<dp[i][j]<<" ";
        cout<<"\n";
    }
*/
    return 0;
}

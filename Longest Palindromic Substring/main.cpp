#include <iostream>

using namespace std;
bool dp[1000][1000];

// Dp approach , but topological sort we used is quite different than usual
int solve(string s,int n)
{
    int i,j;
    int pi,max_length=0;
    for(i=n-1;i>=0;i--)
    {
        for(j=i;j<n;j++)
        {
            if(j-i<=1)
            {
                dp[i][j]= (s[i]==s[j]) ;
            }
            else
            {
                dp[i][j]=dp[i+1][j-1] && (s[i]==s[j]);
            }

            if(dp[i][j] && j-i+1 >=max_length)
            {
                max_length=j-i+1;
                pi=i;
            }
        }
    }

    cout<<s.substr(pi,max_length)<<" "<<max_length<<"\n";
    return max_length;
}
int main()
{
    string s;
    cin>>s;
    solve(s,s.size());
    return 0;
}

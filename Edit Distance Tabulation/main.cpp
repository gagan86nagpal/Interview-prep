#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int dp[2002][2002];

vector < pair <int,int> >  v;


// Idea it to solve sub problems in top sort order of the subproblem graph

// Here top sort comes out to be a diagonal order
// SO sorting is just making this order
// Normal ,row - col wise traversal can also be used, since it is also one of the top sorts

int comp(pair <int,int> p1,pair <int,int> p2)
{
    int s1=p1.first+p1.second;
    int s2=p2.first+p2.second;
    return s1>s2;
}

void tabulation(string &a,string &b)
{
    unsigned i,j;
    for(auto p: v)
    {
        i=p.first;
        j=p.second;
        if(i==a.size())
            dp[i][j]=b.size()-j;
        else if(j==b.size())
            dp[i][j]=a.size()-i;
        else if(a[i]==b[j])
            dp[i][j]=dp[i+1][j+1];
        else
        {
            dp[i][j]=min( dp[i+1][j+1],min(dp[i][j+1], dp[i+1][j]) ) +1;
        }
    }
}
int main()
{
    string a,b;
    cin>>a>>b;
    unsigned i,j;
    for(i=0;i<=a.size();i++)
        for(j=0;j<=b.size();j++)
            v.push_back(make_pair(i,j));
    sort(v.begin(),v.end(),comp);
    tabulation(a,b);
    cout<<dp[0][0]<<"\n";
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

vector < pair <int,int > > a;
int dp[10000];
int main()
{
    int i,n,j;
    int x,y;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x>>y;
        a.push_back(make_pair(x,y));
    }

    sort(a.begin(),a.end()); // we can also sort the pairs
    dp[0]=1;
    for(i=1;i<n;i++)
    {
        int ma=0;
        for(j=0;j<i;j++)
        {
            if(a[i].first > a[j].second)
                ma=max(ma,dp[j]);
        }
        dp[i]=ma+1;
    }
    int ma=0;
    for(i=0;i<n;i++)
        ma=max(ma,dp[i]),cout<<dp[i]<<" ";
    cout<<"\n";
    cout<<ma<<"\n";
    return 0;
}


/*
5
5 24
39 60
15 28
27 40
50 90
*/

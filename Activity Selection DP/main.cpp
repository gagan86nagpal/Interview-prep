#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector < pair <int,int>  > timings;
// Dynamic Programming Solution


int dp[1002][1002];
void init(int n)
{
    int i,j;
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            dp[i][j]=-1;
}

// Also printing the indexes of the selected activity
int maxActivity(int i,int j,int n)
{
    if(i==n+1)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];

   if(j==0) // we have not chosen any activity yet
    return dp[i][j]= max(maxActivity(i+1,0,n) ,1+ maxActivity(i+1,i,n));

   else
   {
       if(timings[j].first <= timings[i].second)
        return dp[i][j]=max(maxActivity(i+1,j,n) ,1+ maxActivity(i+1,i,n));
       else
        return dp[i][j]= maxActivity(i+1,j,n);
   }

}

int main()
{
    int t,n,i,s,f;
    cin>>t;
    while(t--)
    {
        timings.clear();
        cin>>n;
        init(n);
        timings.push_back(make_pair(-1,-1)); // to make 1 based indexing
        for(i=0;i<n;i++)
        {
            cin>>s>>f;
            timings.push_back(make_pair(f, s));
        }
        sort(timings.begin(),timings.end());
        int ans =  maxActivity(1,0,n);
        cout<<ans<<"\n";
    }
    return 0;
}


/*
3
3
3 9
2 8
6 9

4
1 7
5 8
7 8
1 8

6
7 9
0 10
4 5
8 9
4 10
5 7

*/

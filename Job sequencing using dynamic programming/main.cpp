#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;
vector < pair< int,int> > jobs;

pair <int,int>  dp[101][101];
void init(int n)
{
    int i,j;
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            dp[i][j]={-1,-1};
}
pair <int,int> solve(int jobs_taken,int i,int n)   // return number of jobs,profit
{
    if(i==n)
        return {0,0};
    if(dp[jobs_taken][i]!=make_pair(-1,-1))
        return dp[jobs_taken][i];
    int deadline = jobs[i].first;
    int profit = jobs[i].second;
    if(jobs_taken < deadline)
    {
        pair <int,int> take =  solve(jobs_taken+1,i+1,n);
        pair <int,int> not_taken  = solve(jobs_taken,i+1,n);
        if(take.second+profit > not_taken.second)
            return dp[jobs_taken][i]=make_pair(take.first+1,take.second+profit);
        else
            return dp[jobs_taken][i]=not_taken;
    }
    return dp[jobs_taken][i]=solve(jobs_taken,i+1,n);
}
int main()
{
   int i,t;
   int id,d,p;
   int n;
   cin>>t;
   while(t--)
   {
       jobs.clear();
       cin>>n;
       init(n);
       for(i=0;i<n;i++)
       {
           cin>>id>>d>>p;
           jobs.push_back({d,p});
       }
       sort(jobs.begin(),jobs.end());
    pair<int,int> ans = solve(0,0,n);
    cout<<ans.first<<" "<<ans.second<<"\n";
   }
    return 0;
}

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
vector < pair <int, pair < int,int> > >jobs;

// Idea is whether  we can take a job or not
// So , at every call , we have information about the last job we have taken and have two choices whehter to take this
// or not

// If we dont want sort , then we have to maintain two times , minimum time that our job will start and max time
// This will take (time^2 * n ) time

// Better idea is to first sort according to finish time , and in this way  we can just keep track of index of
// last selected job and thus we have an checking mechanism

// After sorting , this problem gets reduced to LIS, so a segment tree solution also exists which would solve this in nlogn time
int dp[1000][1000];

void init(int n)
{
    int i,j;
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            dp[i][j]=-1;
}
int solve(int fin, int in,int n)
{
    if(in==n+1)  // no jobs left
        return 0;
    if(dp[fin][in]!=-1)
        return dp[fin][in];
    if(  jobs[fin].first<=  jobs[in].second.first) // i can schedule this
    {
        int schedule = jobs[in].second.second+ solve(in,in+1,n);
        int dontSchedule = solve(fin,in+1,n);
        return dp[fin][in]= max(schedule,dontSchedule);
    }
    else  // I cannot schedule this
    {
        int dontSchedule = solve(fin,in+1,n);
        return dp[fin][in]=dontSchedule;
    }
}
int main()
{
    int n,s,f,p;
    int i;
    cin>>n;
    init(n);
    jobs.push_back(make_pair(0,make_pair(0,0)));
    for(i=1;i<=n;i++)
    {
        cin>>s>>f>>p;
        jobs.push_back(make_pair(f, make_pair(s,p)));  // finish , start, profit
    }
    sort(jobs.begin(),jobs.end());  // sort by their finish time
    int maxProfit = solve(0,1,n);
    cout<<maxProfit<<"\n";
    return 0;
}


/*
4
2 100 200
3 10 20
1 2 50
6 19 100


*/

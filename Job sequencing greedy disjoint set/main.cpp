#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int id[102];
vector < pair <int,int> > jobs;


// greedy approach is , find the maximum profit job and schedule it to the latest time if possible
// Disjoint are used to keep track of latest time,
// TIme is nlong + n  which comes from sorting +  n* (union + find set)
// SPace is O(max(deadline) + n)  , sets are created
int find_parent(int i)
{
    if(id[i]!=i)
        return id[i]=find_parent(id[i]);
    return i;
}
void unionSet(int a ,int b)
{
    int fa = find_parent(a);
    int fb = find_parent(b);
    id[fa]=fb;
}
void createSet(int n)  // id[i] = t ,means deadline "i" can be given a time slot (from t-1  to t) , =0 means no time slot
{
    int i;
    for(i=0;i<=n;i++)
        id[i]=i;
}
void display(int n)
{
    int i;
    for(i=0;i<=n;i++)
        cout<<i<<":"<<id[i]<<"\n";
}
pair <int,int> solve(int n) // return  <number of jobs sequenced,profit>
{
    createSet(101);// set represents a time slot , upto max deadline
    sort(jobs.begin(),jobs.end(),greater<pair<int,int> >() );
    int i;
    int profit=0;
    int scheduled=0;
    for(i=0;i<n;i++)
    {
        int p = jobs[i].first;
        int d = jobs[i].second;
        if(find_parent(d)!=0)   // we can schedule
        {
            scheduled++;
            profit+=p;
         //   cout<<p<<","<<d<<" is scheduled\n";
            unionSet(find_parent(d),find_parent(d)-1);
           // display(n);
        }
    }
    return make_pair(scheduled,profit);
}
int main()
{
    int n;
    int id,d,p,t;
    int i;
    cin>>t;
    while(t--)
    {
        jobs.clear();
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>id>>d>>p;
            jobs.push_back(make_pair(p,d));
        }
         pair < int,int> ans = solve(n);
        cout<<ans.first<<" "<<ans.second<<"\n";
    }
    return 0;
}

/*

2
4
1 4 20
2 1 10
3 1 40
4 1 30
5
1 2 100
2 1 19
3 2 27
4 1 25
5 1 15
*/

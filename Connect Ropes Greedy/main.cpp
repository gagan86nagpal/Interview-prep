#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// Since, ropes first included will be contributing more to the final cost
// So , optimal strategy is to pick the small ropes first
// Using priority queue
int a[1000];
int minCost(int n)
{
    priority_queue < int , vector <int> , greater <int> > pq;
    int i;
    for(i=0;i<n;i++)
        pq.push(a[i]);
    int cost=0;
    while(pq.size()>1)
    {
        int f=pq.top();
        pq.pop();
        int s = pq.top();
        pq.pop();
        cost+=f+s;
        pq.push(s+f);
    }
    return cost;
}
int main()
{
    int i,n;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    int cost = minCost(n);
    cout<<cost<<"\n";
    return 0;
}

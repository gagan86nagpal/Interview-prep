#include <iostream>
#include <set>
#include <vector>
using namespace std;
/*
Given a number of friends who have to give or take some amount of money from one another.
 Design an algorithm by which the total cash flow among all the friends is minimized.
Link : http://www.geeksforgeeks.org/minimize-cash-flow-among-given-set-friends-borrowed-money/
*/
vector < pair <int,int> > graph[1000];
set < pair <int,int>  > amount_set;
int amount_array[1000];

void minCashFlow(int v)
{
    int min_amount;
    while( amount_set.rbegin()->first >0) // while there are some cash flows left to handle
    {
        pair <int,int> pmin,pmax;
        pmin=*amount_set.begin();
        pmax=*amount_set.rbegin();
        min_amount = min(-pmin.first,pmax.first);
        cout<<pmin.second<<" will give "<<min_amount<<" to "<<pmax.second<<"\n";
        amount_set.erase(pmin);
        amount_set.erase(pmax);
        pmin.first=pmin.first+min_amount;
        pmax.first=pmax.first-min_amount;
        amount_set.insert(pmin);
        amount_set.insert(pmax);
    }
}
int main()
{
   int v,e;
   int a,b,w;
   cin>>v>>e;
   int i;
   for(i=0;i<e;i++)
   {
       cin>>a>>b>>w;
       graph[a].push_back(make_pair(b,w));
       amount_array[a]-=w;
       amount_array[b]+=w;
   }
   for(i=0;i<v;i++) // 0 based indexing
    amount_set.insert(make_pair(amount_array[i],i));

   minCashFlow(v);
    return 0;
}


/*
4 5
0 2 20
0 1 40
1 3 10
1 2 80
3 2 10
*/


/*
3 3
0 1 1000
0 2 2000
1 2 4000
*/

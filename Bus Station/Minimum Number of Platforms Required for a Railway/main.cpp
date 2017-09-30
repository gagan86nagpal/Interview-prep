#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<pair < int,int> >  v;
set < int> dep_times;
int main()
{
    int n;
    int i;
    int s,e;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>s>>e;
        v.push_back(make_pair(s,e));
    }
    sort(v.begin(),v.end());
    // on the basis of start time
    int platforms_required=0;
    int max_platforms=0;
    for(i=0;i<n;i++)
    {
        int arr=v[i].first;
        int dep=v[i].second;
        if(dep_times.empty())
        {
            platforms_required++;
            dep_times.insert(dep);
        }
        else
        {
            if(*dep_times.begin() > arr)
            {
                platforms_required++;
                dep_times.insert(dep);
            }
            else
            {
                while( !dep_times.empty()&& *dep_times.begin() < arr)
                {
                    dep_times.erase(dep_times.begin());
                    platforms_required--;
                }
                dep_times.insert(dep);
                platforms_required++;
            }
        }
        max_platforms=max(max_platforms,platforms_required);
        cout<<i<<":"<<platforms_required<<"\n";
    }
    cout<<max_platforms<<"\n";
    return 0;
}
/*
6
540 550
580 720
590 680
660 690
900 1140
1080 1200
*/

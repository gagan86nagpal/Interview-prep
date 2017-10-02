#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
vector < pair <int,int> > v;
int main()
{
    int t,cnt,maxcnt;
    int n,i,x;
    cin>>t;
    while(t--)
    {
        cnt=0;
        maxcnt=0;
        v.clear();
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>x;
            v.push_back(make_pair(x,2)); // arrival
        }
        for(i=0;i<n;i++)
        {
            cin>>x;
            v.push_back(make_pair(x,1));  //departure
        }
        sort(v.begin(),v.end());
        for(i=0;i<(int)v.size();i++)
        {
            if(v[i].second==2) // arrival
                cnt++;
            else
                cnt--;
            maxcnt=max(maxcnt,cnt);
        }
        cout<<maxcnt<<"\n";
    }
    return 0;
}

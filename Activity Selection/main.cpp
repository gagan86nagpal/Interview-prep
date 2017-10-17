#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector < pair <int,pair <int,int> > > timings;


// Also printing the indexes of the selected activity
int maxActivity(int n)
{
    int i,j;
    int cnt=0;
    for(i=0;i<n;i++)
    {
        int f =timings[i].first;
        int s =timings[i].second.first;
        int in=timings[i].second.second;
        if(i==0)
        {
            cout<<in+1<<" ";
            j=f; // take i
            cnt++;
            continue;
        }
        if(j<=s)
        {
            cout<<in+1<<" ";
            j=f;
            cnt++;
        }
    }
    cout<<"\n";
    return cnt;
}

int main()
{
    int t,n,i,s,f;
    cin>>t;
    while(t--)
    {
        timings.clear();
        cin>>n;
        for(i=0;i<n;i++)
        {
            cin>>s;
            timings.push_back(make_pair(s,make_pair(-1,-1)));
        }
        for(i=0;i<n;i++)
        {
            cin>>f;
            timings[i]=(make_pair(f, make_pair(timings[i].first ,i) ));
        }
        sort(timings.begin(),timings.end());
        int ans =  maxActivity(n);
        cout<<ans<<"\n";
    }
    return 0;
}


/*
2
6
1 3 0 5 8 5
2 4 6 7 9 9
8
75250 50074 43659 8931 11273 27545 50879 77924
112960 114515 81825 93424 54316 35533 73383 160252
*/

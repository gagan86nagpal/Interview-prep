#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

vector < pair< int,int> > indices;
int a[21][21];
int comp(pair <int,int> p1,pair<int,int> p2)
{
    int s1,s2;
    s1=p1.first+p1.second;
    s2=p2.first+p2.second;
    if(s1!=s2)
        return s1<s2;
    return p1.first<p2.first;
}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        indices.clear();
        int i,j;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>a[i][j],indices.push_back(make_pair(i,j));
        sort(indices.begin(),indices.end(),comp);
        for(i=0;i<(int)indices.size();i++)
            cout<<a[indices[i].first][indices[i].second]<<" ";
        cout<<"\n";
    }
    return 0;
}

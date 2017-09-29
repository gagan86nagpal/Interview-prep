#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
int dp[1002][1002];


// Idea is to first solve the subproblems as they are needed in the graph
// So , generating a diagonal pattern by sorting on the basis of (i+j) , where i is row index
// j is column index

// Normal traversal
// j=m-1...0
//   i=n-1...0 , would also have worked
vector < pair <int,int> >  v;
int gen[1002][1002];
int comp(pair <int,int> p1,pair <int,int> p2)
{
    int s1=p1.first+p1.second;
    int s2=p2.first+p2.second;
    return s1>s2;
}
void printLcs(string &a,int n,int m)
{

    unsigned i=0, j=0;
    while(i<n && j<m)
    {
        if(gen[i][j]==1)
       {
           cout<<a[i]<<" ";
           i++;
           j++;
       }
        else if(gen[i][j]==2)
            j++;
        else
            i++;
    }
    cout<<"\n";
}
void tabulation(string &a,string &b)
{
    int i,j;
    for(auto p: v)
    {
        i=p.first;
        j=p.second;
        if(a[i]==b[j])
        {
            dp[i][j]=dp[i+1][j+1]+1;
            gen[i][j]=1;
        }
        else
        {
            if(dp[i][j+1] > dp[i+1][j])
            {
                dp[i][j]=dp[i][j+1];
                gen[i][j]=2;
            }
            else
            {
                dp[i][j]=dp[i+1][j];
                gen[i][j]=3;
            }
        }
    }
}
int main()
{
    string a,b;
    cin>>a>>b;
    unsigned i,j;
    for(i=0;i<a.size();i++)
        for(j=0;j<b.size();j++)
            v.push_back(make_pair(i,j));
    sort(v.begin(),v.end(),comp);
    tabulation(a,b);
    printLcs(a,a.size(),b.size());
    return 0;
}

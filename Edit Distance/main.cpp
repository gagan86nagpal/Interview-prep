#include <iostream>

using namespace std;
int editDistance(string &a , string &b,unsigned i,unsigned j)
{
    if(i==a.size()) // a is exhausted
    {
        return b.size()-j;
    }
    if(j==b.size())
    {
        return a.size()-i;
    }
    if(a[i]==b[j])
        return editDistance(a,b,i+1,j+1);
    else
    {
        int x,y,z;
        x=editDistance(a,b,i+1,j+1)+1;
        y=editDistance(a,b,i+1,j)+1;
        z=editDistance(a,b,i,j+1)+1;
        return min(x, min(y,z) );
    }
}
int main()
{
    string a,b;
    cin>>a>>b;
    int ans=editDistance(a,b,0,0);
    cout<<ans<<"\n";
    return 0;
}

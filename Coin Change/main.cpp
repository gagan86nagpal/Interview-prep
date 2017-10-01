#include <iostream>
#include <string>
#include <vector>
#include <sstream>

namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}
using namespace std;
vector <int> v;
int dp[1000];
int coinChange(int n,int m,string result)
{
    if(n<0)
        return 0;
    if(n==0)
    {
        cout<<result.substr(1)<<"\n";
        return 1;
    }
    if(m==-1)
        return 0;
    return coinChange(n-v[m],m,result+" "+patch::to_string(v[m]) )+coinChange(n,m-1,result);
}
int main()
{
    int n,m,x;
    cin>>m>>n;
    for(int i=0;i<m;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    int ans=coinChange(n,m-1,"");
    cout<<ans<<"\n";
    return 0;
}

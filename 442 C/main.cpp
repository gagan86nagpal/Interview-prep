#include <iostream>
#include <vector>
using namespace std;
vector <int> ans;
void solve(int l,int r)
{
    int m = (l+r)/2;
    if((r-l+1)%4==1)
        m--;
    if(l>r)
        return;
    if(l==r)
    {
        ans.push_back(l);
        return ;
    }
    ans.push_back(m);
    solve(l,m-1);
    solve(m+1,r);
    ans.push_back(m);
}
int main()
{
    int n;
    cin>>n;
    solve(1,n);
    cout<<ans.size()<<"\n";
    for(int x:ans)
        cout<<x<<" ";
    cout<<"\n";
    return 0;
}

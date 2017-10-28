#include <iostream>

using namespace std;
int minBombs(int l,int r)
{
    if(l>r)
        return 0;
    if(l==r)
        return 1;
    int ans=1000000;
    int i;
    for(i=l+1;i<r;i++)
    {
        ans = min(ans,2+minBombs(l,i-1) + minBombs(i+1,r));
    }
    ans = min(ans,2+minBombs(l+1,r));
    ans = min(ans,2+minBombs(l,r-1));
    return ans;
}
int main()
{
    int i,n;
    n=20;
    for(i=2;i<=n;i++)
        cout<<i<<"\t"<<minBombs(1,i)<<"\n";
    return 0;
}

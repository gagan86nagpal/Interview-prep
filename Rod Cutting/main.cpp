#include <iostream>

using namespace std;

int price[1000]; // 1 based indexing
int dp[1000];
void init(int w)
{
    int i;
    for(i=0;i<=w;i++)
        dp[i]=-1;
}
int cut(int w,int n)
{
    if(w<=0)
        return 0;
    if(dp[w]!=-1)
        return dp[w];
    int i;
    int ma=0;
    for(i=1;i<=n;i++)
    {
        if(w>=i)
            ma=max(ma,price[i]+cut(w-i,n));
    }
    return dp[w]=ma;
}

int main()
{
    int n,w;
    int i;
    cin>>n>>w;
    init(w);
    for(i=0;i<n;i++)
    {
        cin>>price[i+1];
    }
    int max_cost = cut(w,n);
    cout<<max_cost<<"\n";
    return 0;
}

/*

8 8
 1   5   8   9  10  17  17  20

8 8
3   5   8   9  10  17  17  20
*/

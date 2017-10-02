#include <iostream>

using namespace std;

int dp[1000][1000];
void init(int egg,int floor)
{
    int i, j;
    for(i=0;i<=egg;i++)
        for(j=0;j<=floor;j++)
            dp[i][j]=-1;
}
int minEgg(int egg,int floors)
{
    if(floors==0||floors==1)
        return floors;

    if(egg==1)
        return floors;
    if(dp[egg][floors]!=-1)
        return dp[egg][floors];
    int i;
    int mi=100000;
    for(i=1;i<=floors;i++)
    {
        int a=minEgg(egg-1,i-1);
        int b=minEgg(egg,floors-i);
        int ma=max(a,b );
        mi=min(mi,ma );
    }
    return dp[egg][floors]=mi+1;

}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int eggs,floors;
        cin>>eggs>>floors;
        init(eggs,floors);
        int ans=minEgg(eggs,floors);
        cout<<ans<<"\n";
    }
    return 0;
}

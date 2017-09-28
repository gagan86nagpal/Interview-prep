#include <iostream>

using namespace std;
int ma[1000];
int dp[1000][1000];
int a[1000];

int lis(int n)
{
   int i,j;
    for(i=0;i<=n-1;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(a[j]>a[i])
                dp[j][i]=1+ma[i];
            else
                dp[j][i]=ma[i];
            ma[j]=max(ma[j],dp[j][i]);

        }
    }
    return ma[n];

}
int main()
{
   int n;
   cin>>n;
   a[0]=-1;
   for(int i=1;i<=n;i++)
    cin>>a[i];
    int ans = lis(n);
    cout<<"LIS Lengthx`:"<<ans<<"\n";
    return 0;
}


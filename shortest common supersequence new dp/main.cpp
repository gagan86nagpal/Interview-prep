#include <iostream>

using namespace std;
string a,b;

int dp[100][100];
int gen[100][100];
void init(int n,int m)
{
    int i ,j;
    for(i=0;i<=n;i++)
        for(j=0;j<=m;j++)
            dp[i][j]=-1;
}

void print(int i,int j,int n,int m)
{
    if(i==n && j==m)
        return ;
    if(i==n)
    {
        cout<<b.substr(j);
        return;
    }
    if(j==m)
    {
        cout<<a.substr(i);
        return;
    }
    if(gen[i][j]==3)
    {
        cout<<a[i];
        print(i+1,j+1,n,m);
    }
    else if(gen[i][j]==1)
    {
        cout<<a[i];
        print(i+1,j,n,m);
    }
    else
    {
        cout<<b[j];
        print(i,j+1,n,m);
    }

}
int scs(int i,int j,int n,int m)
{
    if(i==n)
        return m-j;
    if(j==m)
        return n-i;

    if(dp[i][j]!=-1)
        return dp[i][j];
    if(a[i]==b[j])
    {
        dp[i][j]= 1+scs(i+1,j+1,n,m);
        gen[i][j]=3;
        return dp[i][j];
    }
    int s= scs(i,j+1,n,m) ;
    int f =  scs(i+1,j,n,m);
    if(s>f)
    {
        dp[i][j]=1+f;
        gen[i][j]=1;
    }
    else
   {
       dp[i][j]=s+1;
       gen[i][j]=2;
   }
    return dp[i][j];
}
int main()
{
    cin>>a>>b;
    init(a.size(),b.size());
    int ans = scs(0,0,a.size(),b.size());
    cout<<ans<<"\n";
    print(0,0,a.size(),b.size());
    return 0;
}

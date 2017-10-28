#include <iostream>

using namespace std;
int lefta[5001], righta[5001], prefix_sumb[5001];
int main()
{
    string s;
    cin>>s;

    int i,n;
    n=s.size();
    int cnt=0;
    for(i=0;i<n;i++)
    {
        if(s[i]=='a')
            cnt++;
        lefta[i]=cnt;
      //  cout<<cnt<<" ";
    }
    //cout<<"\n";
    cnt=0;
    for(i=n-1;i>=0;i--)
    {
        if(s[i]=='a')
            cnt++;
        righta[i]=cnt;
       // cout<<cnt<<" ";
    }

    for(i=0;i<n;i++)
    {
        if(i==0 &&s[i]=='b')
            prefix_sumb[i]=1;
        else if(s[i]=='b')
            prefix_sumb[i]=prefix_sumb[i-1]+1;
        else
            prefix_sumb[i]=prefix_sumb[i-1];
    }

    int j;
    int ans=0;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            int x=0,y=0,z=0;
            if(i>0)
                x = lefta[i-1];
            if(j<n-1)
                z = righta[j+1];
            y= prefix_sumb[j];
            if(i>0)
                y-=prefix_sumb[i-1];
            int l = x+y+z;
          //  cout<<i<<":"<<j<<"\t"<<l<<"\n";
            if(ans < l)
                ans=l;
        }
    }
    ans = max(ans,lefta[n-1]);
    cout<<ans<<"\n";
    return 0;
}

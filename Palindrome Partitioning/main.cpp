#include <iostream>

using namespace std;
string a;
bool isPalindrome[1000][1000];
void populateIsPalindome(int n)
{
    int gap;
    int r_s;
    int r_e,i;
    for(gap=0;gap<=n;gap++)
    {
        r_s=0;
        r_e=n-gap;
        for(i=r_s;i<=r_e;i++)
        {
            if(gap==0)
            {
                isPalindrome[i][i+gap]=1;
                continue;
            }
            if(gap==1)
            {
                isPalindrome[i][i+gap]=(a[i]==a[i+1]);
                continue;
            }
            if(a[i]==a[i+gap] && isPalindrome[i+1][i+gap-1])
                isPalindrome[i][i+gap]=1;
            else
                isPalindrome[i][i+gap]=0;
        }
    }
}
int min_cut(int s,int e)
{
    int i;
    if(isPalindrome[s][e])
        return 0;
    int mi=a.size();
    for(i=s;i<=e-1;i++)
    {
        mi=min(min_cut(s,i) + min_cut(i+1,e) +1,mi);
    }
    return mi;
}
int main()
{
    cin>>a;
    populateIsPalindome(a.size()-1);

    int i,j;
    for(i=0;i<a.size();i++)
    {
        for(j=0;j<a.size();j++)
            cout<<isPalindrome[i][j]<<" ";
        cout<<"\n";
    }
    int ans=min_cut(0,a.size()-1);
    cout<<ans<<"\n";
        return 0;
}

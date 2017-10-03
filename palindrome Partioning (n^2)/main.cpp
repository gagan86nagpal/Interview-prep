#include <iostream>

using namespace std;
string a;
int dp[1000];
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
int min_cut(int in)
{
    if(isPalindrome[0][in])
        return 0;
    int i;
    int mi=a.size();
    for(i=0;i<=in-1;i++)   // linear
    {
        if(isPalindrome[i+1][in])  // O(1)
            mi=min(mi,min_cut(i)+1);
    }
    return mi;
}
int main()
{
    cin>>a;
    populateIsPalindome(a.size()-1); // n^2
    int ans=min_cut(a.size()-1);   // n^2
    cout<<ans<<"\n";
        return 0;
}

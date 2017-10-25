#include <iostream>

using namespace std;
string a,b;

bool checkSubsequence(int i,int j)
{
    if(i==(int)a.size())
        return true;
    if(j==(int)b.size())
        return false;
    if(a[i]==b[j])
        return checkSubsequence(i+1,j+1);
    return checkSubsequence(i,j+1);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b;
        int ans = checkSubsequence(0,0);
        cout<<ans<<"\n";
    }
    return 0;
}

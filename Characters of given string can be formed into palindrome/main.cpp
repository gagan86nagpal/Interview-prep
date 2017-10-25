#include <iostream>

using namespace std;
int m[256];
void init()
{
    int n=256;
    for(int i=0;i<n;i++)
        m[i]=0;
}
string check(string s)
{
    int cnt = ((int)s.size() )%2 ;
    // Number of odd elements allowed
    int i;
    for(i=0;i<256;i++)
    {
        if(m[i]%2==1)
            cnt--;
    }
    if(cnt<0)
        return "No";
    else
        return "Yes";
}
int main()
{
    string s;
    cin>>s;
    int i;
    init();
    for(i=0;i<(int)s.size();i++)
        m[(int)s[i]]++;
    string ans = check(s);
    cout<<ans<<"\n";
    return 0;
}

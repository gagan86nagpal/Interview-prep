#include <iostream>
#include <set>
using namespace std;


set<string>  s;
int main()
{
    s.insert("Danil");
    s.insert("Olya");
    s.insert("Slava");
    s.insert("Ann");
    s.insert("Nikita");
    string in;
    cin>>in;
    int i,j;
    int cnt=0;
    int n=in.size();
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            string x=in.substr(i,j-i+1);
            if(s.find(x)!=s.end())
                cnt++;
        }
    }
    if(cnt==1)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}

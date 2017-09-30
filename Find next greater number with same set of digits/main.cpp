#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


string great(string s)
{
    int i;
    char min_index=s.size()-1;
    bool flag=false;
    for(i=s.size()-1;i>0;i--)
    {
        if(s[i]>s[i-1]) // fault found
        {
            flag=true;
            break;
        }
       if(s[min_index]>s[i])
        min_index=i;
    }
    if(!flag)
        return s;
    char temp=s[i-1];
    s[i-1]=s[min_index];
    s[min_index]=temp;
    reverse(s.begin()+i,s.end());
    return s;
}
int main()
{
    string s;
    cin>>s;
    string ans=great(s);
    if(ans==s)
        cout<<"Not Possible";
    else
        cout<<ans<<"\n";
    return 0;
}

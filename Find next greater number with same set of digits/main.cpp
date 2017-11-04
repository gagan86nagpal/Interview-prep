#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


string great(string s)
{
    int i;
    bool flag=false;
    int pos_fault;
    for(i=s.size()-1;i>0;i--)
        if(s[i]>s[i-1]) // fault found
        {
            pos_fault =i-1;
            flag=true;
            break;
        }
    if(!flag)  // NOT possible
        return s;
    char min_index= i;
    while(i<(int)s.size())
    {
        if(s[i] > s[pos_fault] && s[min_index]>s[i])
            min_index=i;
        i++;
    }
    swap(s[pos_fault],s[min_index]);
    reverse(s.begin()+pos_fault+1,s.end());
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

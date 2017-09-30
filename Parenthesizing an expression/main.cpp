#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


vector < char > m[100];
map <string , bool > dp;
map < string,int> gen;

void print(string x)
{
    cout<<gen[x]<<"\n";
}
bool parenthesize(string x,string final_val)
{
    if(dp.find(x)!=dp.end()) // found
        return dp[x];
    cout<<x<<"\n";
    int i;
    bool flag=false;
    if(x==final_val)
        return true;
    for(i=0;i<(int)x.size()-1;i++)
    {
        // multiply x[i]*x[i+1]
        char c=m[ x[i]-'a' ][ x[i+1]-'a'];
        string temp=x.substr(0,i)+c+x.substr(i+2);
        flag=flag||parenthesize(temp,final_val);
        if(flag)
            break;
    }
    return dp[x]=flag;
}
int main()
{
    int n;
    int i,j;
    char c;
    cin>>n;
    string exp,final_val;
    bool ans;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cin>>c;
            m[i].push_back(c);
        }
    }
    cin>>exp>>final_val;
    ans=parenthesize(exp,final_val);
   cout<< (ans?"Yes":"No");
   print(exp);
    return 0;
}


/*
3
b b a
c b a
a c c
bbbbac a
*/

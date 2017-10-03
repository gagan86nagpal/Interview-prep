#include <iostream>
#include <utility>
#include <string>
using namespace std;
 string operands,operators;


pair <int,int> dp[1000][1000];

void init(int n)
{
    int i,j;
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            dp[i][j]=make_pair(-1,-1);
}
pair <int,int> booleanParanthesization(int i,int j)
{
    if(i==j)
     {
        if(operands[i]=='T')
            return make_pair(1,0);
        else
            return make_pair(0,1);
    }
    if(dp[i][j]!=make_pair(-1,-1))
        return dp[i][j];
    int k;
    int tcnt=0;
    int fcnt=0;
    for(k=i;k<=j-1;k++)
    {
        pair <int,int> s1 = booleanParanthesization(i,k);
        pair <int,int> s2 = booleanParanthesization(k+1,j);
        if(operators[k]=='|')
        {
            tcnt+=s1.first*s2.first + s1.first*s2.second + s1.second*s2.first;
            fcnt+=s1.second*s2.second;
        }
        else if(operators[k]=='^')
        {
            tcnt+=s1.first*s2.second + s1.second*s2.first;
            fcnt+= s1.first*s2.first + s1.second*s2.second;
        }
        else // and
        {
            fcnt+=s1.second*s2.second + s1.first*s2.second + s1.second*s2.first;
            tcnt+=s1.first*s2.first;
        }
    }
    return dp[i][j]=make_pair(tcnt,fcnt);
}
int main()
{

   cin>>operands;
   cin>>operators;
   init(operands.size());
   pair <int,int> ans=booleanParanthesization(0,operands.size()-1);
   cout<<ans.first<<"\n";
    return 0;
}

/*
TTFT
|&^
*/

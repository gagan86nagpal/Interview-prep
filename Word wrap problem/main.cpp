#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int a[1000];
vector< pair<int,int> > printLines;
long long cube(long long n)
{
    return n*n*n;
}

char gen[101][102];
int dp[101][102];
void init(int n,int l)
{
    int i,j;
    for(i=0;i<=n+1;i++)
        for(j=0;j<=l+1;j++)
            {
                dp[i][j]=-1;
                gen[i][j]='o';
            }
}
int wordWrap(int line,int characters_left,int in,int n,int line_width)
{
    if(in==n)
        return 0; // last line cost
    if(dp[in][characters_left+1]!=-1)
        return dp[in][characters_left+1];
   //   if(dp[in][characters_left+1]!=-1)
    //        cout<<in<<","<<characters_left<<":"<<dp[in][characters_left+1]<<"---------\n";
    if(characters_left==line_width)// have to take
    {
         int same_line   = 0 + wordWrap(line,characters_left-a[in]-1,in+1,n,line_width);
         gen[in][characters_left]='s';
    //     cout<<in<<","<<characters_left<<":"<<same_line<<"\n";
         return dp[in][characters_left+1]=same_line;
    }
    if(characters_left>=a[in]) // we can accommodate this word here only
    {
        int same_line   = 0 + wordWrap(line,characters_left-a[in]-1,in+1,n,line_width);
        int next_line   = cube(characters_left+1) + wordWrap(line+1,line_width,in,n,line_width);

        if(same_line > next_line)
        {
            gen[in][characters_left]='n';

    //     cout<<in<<","<<characters_left<<":"<<next_line<<"\n";
            return dp[in][characters_left+1]=next_line;
        }
        else
        {
            gen[in][characters_left]='s';

    //     cout<<in<<","<<characters_left<<":"<<same_line<<"\n";
            return dp[in][characters_left+1]=same_line;
        }
    }
    // we cannot accommodate
      int next_line   = cube(characters_left+1) + wordWrap(line+1,line_width,in,n,line_width);
       gen[in][characters_left]='n';

   //      cout<<in<<","<<characters_left<<":"<<next_line<<"\n";
       return dp[in][characters_left+1]=next_line;
}

void printAnswer(int n,int l)
{
    int i=0,j=l;
    int line=1;
    while(i<n)
    {
        if(gen[i][j]=='n') // next line
        {
            line++;
            j=l;
        }
        else if(gen[i][j]=='s') // same line
        {
            printLines.push_back(make_pair(line,i+1));
            i++;
            j = j - a[i-1]-1;
        }
        else
        {
            break;
        }
    }

    line=1;
    for(i=0;i<(int)printLines.size();i++)
    {
        if(i==0)
            cout<<1<<" ";
        else if(printLines[i].first!=line)
        {
            cout<<i<<" "<<i+1<<" ";
            line=printLines[i].first;
        }
    }
    cout<<i<<"\n";
}
int main()
{
    int n;
    int i,line_width;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    cin >>line_width;
    init(n,line_width);
    int minCost = wordWrap(0,line_width,0,n,line_width);

    printAnswer(n,line_width);
    cout<<"minCOst:"<<minCost<<"\n";
    return 0;
}

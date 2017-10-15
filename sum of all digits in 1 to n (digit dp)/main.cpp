#include <iostream>
#include <math.h>
#include <map>
using namespace std;
// Seems complicated to understand
// Refer geeks for geeks

long long pow10(int p)
{
    if(p==0)
        return 1;
    long long a = pow10(p/2);
    if(p%2==1)
        return a*a*10;
    return a*a;
}

map < long long,long long > dp ;// as we can have n> 10^9 , so we need a map
long long solve(long long x)
{
    if(x<10)
        return (x*(x+1) )/2;
    if(dp.find(x)!=dp.end())
        return dp[x];
   int d= log10(x)+1;  // number of digits
   long long p = pow10(d-1);
   int msb=x/p;
   int rest = x%p;
   if(pow10(d)==x+1) // x is of the form 9 ,99 ,999                      case 1  , recuse into case 1
        return dp[x]=solve(x/10)*10  + p*45;
   if(rest==0)  // x is like 100,40000,20000,60000,1000                  case 2       , recurse into case 1 subproblem
       return dp[x]= solve(p-1)*msb +  ((msb*(msb-1 ) )/2) *(p)  +msb;
   else   // general solution                                             case 3 .recurse into case3 + case 2 sub problem
    return dp[x]=solve(p*msb) + msb*(rest) + solve(rest);

}
int main()
{
    long long  t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<solve(n)<<"\n";
    }
    return 0;
}
/*
901
1902
3003
4204
5505

*/

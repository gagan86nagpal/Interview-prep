#include <iostream>
#include <set>
using namespace std;
string a;
set< string> all_perms;
void allDistinctPermutations(int s,int e)
{
    if(s==e)
        all_perms.insert(a);
    int i;
    for(i=s;i<=e;i++)
    {
        if(i==s || a[i]!=a[s])
        {
            swap(a[i],a[s]);
            allDistinctPermutations(s+1,e);
            swap(a[i],a[s]);
        }
    }
}
int main()
{
    cin>>a;
   allDistinctPermutations(0,a.size()-1);
   for(string x: all_perms)
    cout<<x<<"\n";
    return 0;
}

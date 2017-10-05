#include <iostream>
using namespace std;
string a;

void allDistinctPermutations(int s,int e)
{
    if(s==e)
        cout<<a<<"\n";
    int i;

    char m[26];
    for(i=0;i<26;i++)
        m[i]=-1;
    for(i=s;i<=e;i++)
    {
        if(m[a[i]-'a']==-1)  // if we have seen this character then swapping it will result in same permutation
            m[a[i]-'a']=1;
        else
            continue;

            swap(a[i],a[s]);
            allDistinctPermutations(s+1,e);
            swap(a[i],a[s]);

    }
}
int main()
{
   cin>>a;
   allDistinctPermutations(0,a.size()-1);
    return 0;
}

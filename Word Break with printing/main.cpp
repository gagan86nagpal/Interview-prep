#include <iostream>
#include <set>
#include <string>
using namespace std;
set < string> dict;
string to_search;
// here we are not stoppping if we found a solution, we keep on finding other solutions as well
// When we hit a leaf in recursion tree, we print out output
bool isBreakable(unsigned index,string output)
{
    // Recursion leaf
    if(to_search.size()==index)
    {
        cout<<output.substr(1)<<"\n";
        return true;
    }

    bool flag=false;
    unsigned effective_length = to_search.size()-index;
    for(unsigned i=1;i<=effective_length;i++)
    {
        string sub=to_search.substr(index,i);
         if(dict.find( sub )!=dict.end()) // found
         {
             flag== isBreakable(index+i,output+" "+sub) || flag; // changing the order of RHS may result in boolean shortcut
         }
         // No break if flag is true , as we want to explore all solutions
    }
    return flag;
}
int main()
{
    int n,q;
    string x;
    cin>>n>>q;
    for(int i=0;i<n;i++)
    {
       cin>>x;
       dict.insert(x);
    }
    while(q--)
    {
        cin>>to_search;
        isBreakable(0,"");
    }
    return 0;
}


/*
13 3
i and like sam sung samsung mobile ice cream icecream man go mango
ilike
ilikesamsung
ilikeicecreamandmango



10 1
a b c d e abc abcd bcd cde abcdef
abcde
*/


#include <iostream>

using namespace std;

// Taking all the cases and choosing the minimum among them
int editDistance(string &a , string &b,unsigned i,unsigned j)
{
    if(i==a.size()) // a is exhausted , so cost includes either deleting b characters or inserting characters in a
    {
        return b.size()-j;
    }
    if(j==b.size()) // b is exhausyde, cost is either inserting characters in a or deleting in b
    {
        return a.size()-i;
    }
    if(a[i]==b[j]) // if index is equal , then why to cost an operation on it
        return editDistance(a,b,i+1,j+1);
    else
    {
        int x,y,z;
        x=editDistance(a,b,i+1,j+1)+1;    // Replace cost
        y=editDistance(a,b,i+1,j)+1;       // Inserting in string a or we can say deleting in string b
        z=editDistance(a,b,i,j+1)+1;    // Inserting in string b or we can sat deleting in string a
        return min(x, min(y,z) );   // Taking minimum of three
    }
}
int main()
{
    string a,b;
    cin>>a>>b;
    int ans=editDistance(a,b,0,0);
    cout<<ans<<"\n";
    return 0;
}

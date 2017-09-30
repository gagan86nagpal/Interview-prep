#include <iostream>
#include <string>
using namespace std;
int a[1000];
int main()
{
    int n,q;
    string x;
    int op=0;
    int p;
    int i;
    cin>>n>>q;
    for(i=0;i<n;i++)
        cin>>a[i];
    while(q--)
    {
        cin>>x>>p;
        if(x=="R")
            cout<<a[ (p+op-1+n*2)%n ]<<"\n";
        else if(x=="A")
        {
            op-=p;
             op=(op+n)%n;
        }
        else
        {
            op+=p;
            op=(op+n)%n;
        }
    }
    return 0;
}

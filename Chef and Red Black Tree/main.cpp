#include <iostream>
#include <utility>
#include <math.h>
using namespace std;


pair <int,int> lca(int a,int b)
{
    int re=0;
    int bl=0;
    if( ((int)log2(a))%2==0 )
        bl++;
    else
        re++;
    if( ((int)log2(b))%2==0 )
        bl++;
    else
        re++;
    while(a!=b)
    {
        if(a>b)
        {
            a/=2;
            if( ((int)log2(a))%2==0 )
                bl++;
            else
                re++;
        }
        else
        {
            b/=2;
             if( ((int)log2(b))%2==0 )
                bl++;
            else
                re++;
        }
    }
     if( ((int)log2(a))%2==0 )
        bl--;
    else
        re--;
    return make_pair(re,bl);
}
int main()
{
    int q;
    cin>>q;
    bool flag = true;
    while(q--)
    {
        string st;
        int a,b;
        cin>>st;
        if(st[1]=='i')
            flag=!flag;
        else
        {
            cin>>a>>b;
            pair <int,int> p = lca(a,b);
            if( (st[1]=='b' && flag==true ) || (st[1]=='r'&& flag==false ))
                cout<<p.second<<"\n";
            else
                cout<<p.first<<"\n";
        }
    }
    return 0;
}

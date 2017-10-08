#include <iostream>

using namespace std;

int main()
{
    long long t,n,a,b,c,m=1000000007;
    cin>>t;
    while(t--)
    {
        cin>>n;
        a=0;
        b=1;
        while(n--)
        {
            c=(a+b)%m;
            a=b%m;
            b=c%m;
        }
        cout<<a<<"\n";
    }
    return 0;
}

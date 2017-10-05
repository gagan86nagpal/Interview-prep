#include <iostream>

using namespace std;
bool find_num(long long a)
{
    long long save=a;
    long long ret=0;
    while(a)
    {
        ret=ret*2 + a%2;
        a/=2;
    }
    return save==ret;
}
int main()
{
    int t;
    long long n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<find_num(n)<<"\n";
    }
    return 0;
}

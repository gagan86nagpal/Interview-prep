#include <iostream>

using namespace std;
int fib(int n)
{
    int a,b,c;
    a=1;
    b=1;
    while(n--)
    {
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}
int main()
{
    int n;
    cin>>n;
    int f = fib(n);
    cout<<f*f<<"\n";
    return 0;
}

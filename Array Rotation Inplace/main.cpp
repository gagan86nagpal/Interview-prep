#include <iostream>

using namespace std;

// We are doing a[i] = a[i+d] , and incrementing i by d
// Here , we can get stuck in cycles
// THere are total g = gcd(n,d) cycles , hence repeating this procedure for (g-1) values of length each cycle gives
// us rotated array

// We are making this so much complex because of Linear time and Constant space
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int a[102];
void rotateByN(int si,int n,int d,int g)
{
    int x =a[si];
    int i=si;
    int cnt=n/g -1;
    while(cnt--)
    {
        a[i]=a[ (i+d)%n ];
        i = (i+d)%n;
    }
    a[i]=x;
}
int main()
{
    int n,d;
    cin>>n>>d;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int g = gcd(n,d);
    for(int i=0;i<g;i++)
        rotateByN(i,n,d,g);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    return 0;
}

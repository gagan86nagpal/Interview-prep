#include <iostream>

using namespace std;
// TO generate different tiles
// We can place a tile vertical , so we have n-1 ways to make new tiles
// or we can place two tiles horizontal , so we have n-2 ways
// Recurrence relation is  f(n) = f(n-1) + f(n-2)


// Fibonnaci numbers in logn
long long aux[2][2] = {
                {1ll,1ll},
                {1ll,0ll}
                };
long long ** mul(long long** X,long long** Y)
{
    long long ** ret = new long long*[2];
    ret[0] = new long long[2];
    ret[1] = new long long[2];
    long long a1=X[0][0],b1=X[0][1],c1=X[1][0],d1=X[1][1];
    long long a2=Y[0][0],b2=Y[0][1],c2=Y[1][0],d2=Y[1][1];

    ret[0][0] = a1*a2+b1*c2;
    ret[0][1] = a1*b2+b1*d2;
    ret[1][0] = c1*a2+d1*c2;
    ret[1][1] = c1*b2+d1*d2;
    return ret;
}
long long** pow(long long** A,long long int n) // program to find A^n
{
    if(n==1)
        return A;
    long long **C = pow(A,n/2);
    if(n%2 ==0) // even
        return mul(C,C);
    else
        return mul( mul(C,C) , A);

}
long long fib(long long n )
{
   long long ** mat =new long long *[2];
    mat[0] = new long long[2];
    mat[1] = new long long[2];
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
            mat[i][j]=aux[i][j];
    return pow(mat,n)[0][0];
}
int main()
{
    int n,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<fib(n)<<"\n";
    }
    return 0;
}

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector <int> sub1,a,aux,sub2;
int min_diff=10000;
int findSum(vector <int> x)
{
    int sum=0;
    for(int in : x)
        sum+=a[in];
    return sum;
}
void solve(int in,int n,int sum)
{

    if((int)aux.size()==n/2)
    {
        int sum1 = findSum(aux) ;
        int diff = abs(sum - 2*sum1);
        if( diff < min_diff )
        {
            min_diff = diff;
            sub1 = aux; // copy constructor
        }
        return ;
    }
    if(in==n)
    return;
    // take
    aux.push_back(in);
    solve(in+1,n,sum);
    aux.pop_back();
    // dont take

    solve(in+1,n,sum);

}

void print(vector <int> x ,string msg)
{
    cout<<msg<<":";
    for(int i : x)
        cout<<a[i]<< " ";
    cout<<"\t"<<findSum(x)<<"\n";
}
int main()
{
    int n,i,x;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    int sum=0;
    for(i=0;i<n;i++)
        sum+= a[i];

    solve(0,n,sum);

    // find second subarray
    int pos=0;
    for(i=0;i<n;i++)
    {
        if(i!=sub1[pos])
            sub2.push_back(i);
        else
            pos++;
    }
    print(sub1,"Sub Array 1");
    print(sub2,"Sub Array 2");
    return 0;
}
/*
11
23 45 -34 12 0 98 -99 4 189 -1 4
*/

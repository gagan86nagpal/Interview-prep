#include <iostream>
#include <vector>
using namespace std;

vector <int> solution;
int a[102];

void printSolution()
{
    for(int i: solution)
        cout<<a[i]<<" ";
    cout<<"\t\tindices :";
    for(int i: solution)
        cout<<i<<" ";
    cout<<"\n";
}
void solve(int i,int sum,int req_sum,int n)
{
    if(i==n)
        return;
    if(sum==req_sum)
    {
        printSolution();
        return ;
    }
    if(sum+a[i]> req_sum) // dont take
        solve(i+1,sum,req_sum,n);
    else
    {
        // take it
        solution.push_back(i);
        solve(i+1,sum+a[i],req_sum,n);
        solution.pop_back();


        // dont take it
        solve(i+1,sum,req_sum,n);
    }

}
int main()
{
    int n;
    cin>>n;
    int i;
    for(i=0;i<n;i++)
        cin>>a[i];
    int required_sum;
    cin>>required_sum;
    solve(0,0,required_sum,n);
    return 0;
}


/*
10
1 2 4 3 4 2 6 5 2 3
8

*/

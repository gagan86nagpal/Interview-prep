#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

// Print All solutions
vector < pair < int,int> > queen_position;
int solution[20][20];
void printSolution(int n)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            solution[i][j]=0;
    for (pair <int,int> p: queen_position)
        solution[p.first][p.second]=1;

    cout<<"-------------\n";
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<solution[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"-------------\n";
}
bool isValid(int row,int col)
{
    for(pair <int,int > p : queen_position)
    {
        int x = p.first;
        int y = p.second;
        if(col==y || abs(row-x) ==abs(col-y))
            return false;
    }
    return true;
}
void solve(int row,int n)
{
    if(row==n)
    {
        printSolution(n);
        return ;
    }
    int col;
    for(col=0;col<n;col++)
    {
        if(isValid(row,col))
        {
            queen_position.push_back(make_pair(row,col));
            solve(row+1,n);
            queen_position.pop_back();
        }
    }
}
int main()
{
   int n;
   cin>>n;
   solve(0,n);
    return 0;
}

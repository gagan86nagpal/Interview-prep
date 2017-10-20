#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int grid[10][10];
vector < pair <int,int> > unassigned;

void printSolution()
{
    cout<<"__________________\n\n";
    int i,j;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
            cout<<grid[i][j]<<" ";
        cout<<"\n";
    }
}
bool check(int r,int c,int n)  // if grid[r][c]=n , is valid or not
{
    int i,j;
    for(i=0;i<9;i++)
    {
        if(grid[r][i]==n)
            return false;
        if(grid[i][c]==n)
            return false;
    }
    bool block_found = false;
    for(i=0;i<9;i+=3)
    {
        for(j=0;j<9;j+=3)
            if(i+2>=r && j+2 >=c)
            {
                block_found = true;
                break;
            }
        if(block_found)
            break;
    }
    // i , j at starting of block
    int si = i;
    int sj = j;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            if(grid[si+i][sj+j]==n)
                return false;
    return true;
}

bool solve(int in,int n)
{
    if(in == n-1) // base case
    {
        for(int i=1;i<=9;i++)
        {
            int x = unassigned[in].first;
            int y = unassigned[in].second;
            if(check(x,y,i))
            {
                grid[x][y]=i;
                printSolution();
                return true;
            }
        }
        return false;
    }
    bool ret=false;
    int x= unassigned[in].first;
    int y= unassigned[in].second;
    for(int i=1;i<=9;i++)
        if(check(x,y,i))
        {
            grid[x][y]=i;
            ret = ret ||solve(in+1,n);
            grid[x][y]=0;
        }
    return ret;
}
int main()
{
    int i,j;
    cout<<"Enter the inital valid grid\n";
    for(i=0;i<9;i++)
        for(j=0;j<9;j++)
        {
            cin>>grid[i][j];
            if(grid[i][j]==0)
                unassigned.push_back(make_pair(i,j));
        }

   bool is_solution = solve(0,unassigned.size());
    if(false==is_solution)
        cout<<"No Solution Exists\n";
    return 0;
}
/*
3 1 0 5 0 8 0 9 2
5 0 0 1 3 0 7 0 8
4 8 0 6 0 9 0 3 1
2 0 0 4 0 5 0 8 0
9 0 4 8 0 3 1 0 5
8 0 1 0 0 2 0 4 3
1 3 0 9 0 7 2 5 0
6 0 2 3 0 1 0 7 0
7 0 0 2 0 0 3 1 0

9 0 6 0 7 0 4 0 3
0 0 0 4 0 0 2 0 0
0 7 0 0 2 3 0 1 0
5 0 0 0 0 0 1 0 0
0 4 0 2 0 8 0 6 0
0 0 3 0 0 0 0 0 5
0 3 0 7 0 0 0 5 0
0 0 7 0 0 5 0 0 0
4 0 5 0 1 0 7 0 8
*/

#include <iostream>

using namespace std;

/*
Given a grid with each cell consisting of positive, negative or no points i.e, zero points. We can move across a cell only if we have positive points ( > 0 ). Whenever we pass through a cell, points in that cell are added to our overall points. We need to find minimum initial points to reach cell (m-1, n-1) from (0, 0).

Constraints :

From a cell (i, j) we can move to (i+1, j) or (i, j+1).
We cannot move from (i, j) if your overall points at (i, j) is <= 0.
We have to reach at (n-1, m-1) with minimum positive points i.e., > 0.

*/



/*

Solution:
We can easily observe an optimal substructure and overlapping subproblems here. But even then , writing the
base cases as well as recursion can be very tricky as there are many ways , our recursive function can be written.
Some approaches are :
1. Find the minimum negative value that we can achieve in any path, answer would be 1-value
2. Exactly find the answer as I did.


So , General idea is to stick with 1 approach , write your recursive function as well as bases cases ,
keeping your initial recursive idea in mind and never deviate from it.
If there is a need to deviate , then change your initial idea and then proceed.

*/
int mat[20][20];

int dp[20][20];
int minInitialPoints(int i,int j,int n,int m)
{
    if(i==n && j==m)
        return max(1,1-mat[i][j]);
    int fun;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(i==n)
        fun= minInitialPoints(i,j+1,n,m);
    else if(j==m)
       fun = minInitialPoints(i+1,j,n,m);
    else
        fun=min(minInitialPoints(i,j+1,n,m) , minInitialPoints(i+1,j,n,m));

    if(mat[i][j]==0)
        return dp[i][j]= fun;
    if(mat[i][j]>0)
        return dp[i][j]=max(1,fun-mat[i][j]);
    else
        return dp[i][j]=fun-mat[i][j];
}
void init(int n,int m)
{
    int i,j;
    for(i=0;i<=n;i++)
        for(j=0;j<=m;j++)
            dp[i][j]=-1;
}
int main()
{
    int n,m;
    int i,j;
    cin>>n>>m;
    init(n,m);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            cin>>mat[i][j];

    int ans = minInitialPoints(1,1,n,m);
    cout<<ans<<"\n";
    return 0;
}

/*
3 3
-2 -3 3
-5 -10 1
10 30 -5

2 2
-2 3
-4 -10
*/

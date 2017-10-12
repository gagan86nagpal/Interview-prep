#include <iostream>

using namespace std;
// 1 based indexing
int row_col_sum[101][101];
int mat[101][101];
void calculateRowColumnSum(int n,int m)
{
    int i,j;
    for (i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            row_col_sum[i][j]=mat[i][j] + row_col_sum[i][j-1] + row_col_sum[i-1][j] - row_col_sum[i-1][j-1];
}
int getSumMatrix(int a,int b,int c,int d) // O(1)
{
    return row_col_sum[c][d] + row_col_sum[a-1][b-1] - row_col_sum[c][b-1] - row_col_sum[a-1][d];
}

int maximumSumRectangle(int n,int m)
{
    int l,r;
    // fixing left and right pair
    // finding the max sum in this sub matrix using kadane in linear time
    // hence time complexity is cubic
    int global_max=-(1<<30);
    int gt,gd,gl,gr;
    for(l=1;l<=m;l++)
    {
        for(r=l;r<=m;r++)
        {
            int t=1,d;
            int prefix_sum=0;
            int max_sum=- (1<<30);
            int mt,md;
            for(d=1;d<=n;d++)
            {
                prefix_sum=getSumMatrix(t,l,d,r);

                if(max_sum < prefix_sum)
                    mt=t,md=d,max_sum=prefix_sum;

                if(prefix_sum < 0)
                {
                    prefix_sum=0;
                    t=d+1;
                }

            }
            if(global_max < max_sum)
                    gt=mt,gd=md,gl=l,gr=r,global_max=max_sum;
        }
    }
  //  cout<<gt<<","<<gl<<" - "<<gd<<","<<gr<<"\n";
    return global_max;
}
int main()
{
    int n,m,i,j;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            cin>>mat[i][j];
    calculateRowColumnSum(n,m);
    int ans=maximumSumRectangle(n,m);
    cout<<ans<<"\n";
    return 0;
}

/*
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6


2 2
5 -1
9 1
*/

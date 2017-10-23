#include <iostream>
#include <vector>
using namespace std;
vector <int> intersection,input1;
int mat[100][100];

void solve(int n,int m)
{
    int i,j,k;
    for(i=0;i<m;i++)
        input1.push_back(mat[0][i]);
    for(i=1;i<n;i++)
    {
        intersection.clear();
        j=0;
        k=0;
        while(j<m && k<(int)input1.size())
        {
            if(input1[k]==mat[i][j])
            {
                intersection.push_back(input1[k]);
                k++;
                j++;
            }
            else if(input1[k] > mat[i][j])
                j++;
            else
                k++;
        }
        input1 = intersection;
    }
    for(int x: intersection)
        cout<<x<<" ";
    cout<<"\n";
}
int main()
{
    int n,m;
    int i,j;
    cin>>n>>m;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            cin>>mat[i][j];
    solve(n,m);
    return 0;
}
/*
4 5
1 2 3 4 5
2 4 5 8 10
3 5 7 9 11
1 3 5 7 9

*/

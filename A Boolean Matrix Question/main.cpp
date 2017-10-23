#include <iostream>

using namespace std;
int mat[102][102];
int r[102];
int c[102];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>mat[i][j];
        for(int i=0;i<n;i++)
            r[i]=0;
        for(int j=0;j<m;j++)
            c[j]=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(mat[i][j]==1)
                    r[i]=c[j]=1;

        for(int i=0;i<n;i++)
            if(r[i])
                for(int j=0;j<m;j++)
                    mat[i][j]=1;
        for(int j=0;j<m;j++)
            if(c[j])
                for(int i=0;i<n;i++)
                    mat[i][j]=1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cout<<mat[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
/*
3
2 2
1 0
0 0
2 3
0 0 0
0 0 1
3 4
1 0 0 1
0 0 1 0
0 0 0 0
*/

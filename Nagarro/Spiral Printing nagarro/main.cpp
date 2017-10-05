#include <iostream>

using namespace std;
int n;
int m[100][100];
int vis[100][100];
bool changeDirection(int i, int j,int n)
{
    if(i>=0 && i<=n-1 && j>=0 && j<=n-1 && vis[i][j]==0)
        return false;
    return true;
}
void spiral(int n)
{
    int cnt=n*n;
    char dir='r';
    int i=0,j=0;
    while(cnt--)
    {
        cout<<m[i][j]<<" ";
        vis[i][j]=1;
        if(dir=='r')
            j++;
        else if(dir=='l')
            j--;
        else if(dir=='u')
            i--;
        else // down
            i++;
        if(changeDirection(i,j,n))
        {
            if(dir=='r')
                dir='d',j--,i++;
            else if(dir=='d')
                dir='l',i--,j--;
            else if(dir=='l')
                dir='u',j++,i--;
            else
                dir='r',i++,j++;
        }

    }
}
int main()
{
    int n;
    int i,j;
    cin>>n;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            cin>>m[i][j];
    spiral(n);
    return 0;
}

/*
4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

*/

#include <iostream>

using namespace std;
int mat[101][101];
int x,y; // they will hold the answer if it is found
bool solve(int n,int m,int ele)
{
    int r,c;
    // finding row
    for(r=0;r<n;r++)
        if(mat[r][0] > ele)
            break;
    r--;
    c=0;
    while(r>=0 && c<m)
    {
        if(mat[r][c]==ele)
        {
            x=r;
            y=c;
            return true;
        }
        else
        {
            if(mat[r][c] < ele )
                c++;
            else
                r--;
        }
    }
    return false;
}
int main()
{
    int n,m,ele,i,j;
    cin>>n>>m;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            cin>>mat[i][j];
    cin>>ele;
    bool is_found=solve(n,m,ele);
    if(is_found)
        cout<<x<<" "<<y<<"\n";
    else
        cout<<"0\n";
    return 0;
}
/*
4 4
10 20 30 40
15 25 35 45
27 29 37 48
32 33 39 50
29

4 4
10 20 30 40
15 25 35 45
27 29 37 48
32 33 39 50
100

*/

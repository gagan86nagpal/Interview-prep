#include <iostream>
#include <cmath>
using namespace std;
int chess[100][100];
int vis[100][100];

// Generate all possible moves and check if it can complete tour or not
bool inBounds(int i ,int j,int n)
{
    return i>=0 && i<=n-1 && j>=0 && j<=n-1;
}
bool generate_solution(int move_number,int x,int y,int n)
{
    int i,j;
    bool solution = false;
    chess[x][y]=move_number;
    if(move_number==n*n-1)
        return true;
    for(i=-2;i<=2;i++)
    {
        for(j=-2;j<=2;j++)
        {
            if(abs(i) + abs(j)==3) // all knight moves
            {
                if(inBounds(x+i,y+j,n) && vis[x+i][y+j]==false)
                {
                    vis[x+i][y+j]=1;
                    solution=solution||generate_solution(move_number+1,x+i,y+j,n);
                    vis[x+i][y+j]=0;
                }
            }
        }
    }
    return solution;
}
void printTour(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            cout<<chess[i][j]<<"\t";
        cout<<"\n";
    }
}
int main()
{
    int n;
    cin>>n;
    vis[0][0]=1;
    bool isPossibble=generate_solution(0,0,0,n);
    if(isPossibble)
        printTour(n);
    else
        cout<<"Tour is not Possible\n";
    return 0;
}

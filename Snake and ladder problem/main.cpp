#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int vis[1000];
int moves[1000];   // 1 bases indexing
// if moves[i]=i , then it is a normal node , here i is connected to i+1, i+2,....i+6 as dice's outcome could be anything
// if moves[i] > i, then it is a ladder
// else  , it is a snake

int bfs(int n) // n is number of vertex
{
    queue < pair <int,int>  > q;
    vis[0]=1;
    q.push(make_pair(0,0)); // distance of 0 from 0 is 0

    if(moves[0]!=0)
        q.push(make_pair(moves[0],0)); // if very first node is ladder


    while(!q.empty())
    {
        int a=q.front().first;
        int d=q.front().second;
        q.pop();
        if(a==n-1) // we have reached end of the board
            return d;
        if(moves[a]!=a) // not a normal node
            continue;
        int i;
        for(i=1;i<=6 && a+i<n;i++)
        {
            if(vis[a+i])
                continue;
            if(moves[a+i]!=a+i) // not a normal node
            {
                if(vis[moves[a+i]])
                    continue;
                vis[moves[a+i]]=1;
                q.push(make_pair(moves[a+i],d+1));
            }
            vis[a+i]=1;
            q.push(make_pair(a+i,d+1));
        }
    }
    return -1;  // not reachable
}
int main()
{
   // Let us construct the board given in above diagram
    int n= 30; // 0 based indexing
    for (int i = 0; i<n; i++)
        moves[i] = i;

    // Ladders
    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;

    // Snakes
    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;

    int dist=bfs(n);
    if(dist!=-1)
        cout<<"Minimum distance :"<<dist<<"\n";
    else
        cout<<"Not Reachable\n";
    return 0;
}

#include <iostream>

using namespace std;
int mat[200][200];

void printOuter(int si,int sj,int ei,int ej)
{
    int r,c;
   /* if(si==ei) // one row
    {
        for(c = sj ; c<=ej ;c++)
            cout<<mat[si][c]<<" ";
        return;
    }
    if(sj==ej)  // one column
    {
        for(r=si;r<=ei;r++)
            cout<<mat[r][sj]<<" ";
        return;
    }
    */
    for(c=sj;c<=ej;c++)
        cout<<mat[si][c]<<" ";
    for(r=si+1;r<=ei;r++)
        cout<<mat[r][ej]<<" ";
    if(si!=ei)   // only 1 row
        for(c=ej-1;c>=sj;c--)
            cout<<mat[ei][c]<<" ";
    if(sj!=ej)   // only 1 column
        for(r=ei-1;r>si;r--)
            cout<<mat[r][sj]<<" ";
}
void spiral(int n,int m)
{
    int si,sj,ei,ej;
    si=0;
    sj=0;
    ei=n-1;
    ej=m-1;
    while(si <=ei && sj<=ej)
    {
        printOuter(si,sj,ei,ej);
        si++;
        sj++;
        ei--;
        ej--;
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin>>mat[i][j];
    spiral(n,m);
    return 0;
}
/*
4 4
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

3 3
1 2 3
4 5 6
7 8 9

3 6
1 2 3 4 5 6
7 8 9 10 11 12
13 14 15 16 17 18

6 3
1 2 3
4 5 6
7 8 9
10 11 12
13 14 15
16 17 18
*/

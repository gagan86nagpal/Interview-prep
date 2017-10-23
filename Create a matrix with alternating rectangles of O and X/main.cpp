#include <iostream>

using namespace std;
char mat[200][200];

void printOuter(int si,int sj,int ei,int ej,char x)
{
    int r,c;
    if(si==ei) // one row
    {
        for(c = sj ; c<=ej ;c++)
            mat[si][c]=x;
        return;
    }
    if(sj==ej)  // one column
    {
        for(r=si;r<=ei;r++)
            mat[r][sj]=x;
        return;
    }
    for(c=sj;c<=ej;c++)
        mat[si][c]=x;
    for(r=si+1;r<=ei;r++)
        mat[r][ej]=x;
    for(c=ej-1;c>=sj;c--)
        mat[ei][c]=x;
    for(r=ei-1;r>si;r--)
        mat[r][sj]=x;
}
void spiral(int n,int m)
{
    int si,sj,ei,ej;
    si=0;
    sj=0;
    ei=n-1;
    ej=m-1;
    int i=1;
    while(si <=ei && sj<=ej)
    {
        printOuter(si,sj,ei,ej,((i++)%2?'X':'O'));
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
    spiral(n,m);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<mat[i][j]<<" ";
        cout<<"\n";
    }

    return 0;
}

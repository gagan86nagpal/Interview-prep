#include <iostream>
#include <algorithm>
using namespace std;
char nuts[100],bolts[100];
void print(char [],int);

int part(char x[100],int l,int r,char ch)
{
    int i=l-1;
    int j;
    int pos=-1;
    for(j=l;j<=r;j++)
    {
        if(x[j]==ch)  // marking the position of ch in this array as we will swap it with i+1 in the end
            pos=j;
        if(x[j]<ch)
        {
            if(i+1==pos) // position can change here , very tricky case
                pos = j;
            swap(x[i+1],x[j]);
            i++;
        }
    }
    swap(x[pos],x[i+1]);
    return i+1;
}
void match(int l,int r)
{
    if(l>r)
        return;
       // pick a last element from bolts and use to partition the nuts
    char bolt = bolts[r];
    int i = part(nuts,l,r,bolt);

    // using this pivot index, partition the bolts array
    char nut = nuts[i];
    part(bolts,l,r,nut);
    match(l,i-1);
    match(i+1,r);
}

void print(char x[100],int n)
{
    int i;
    for(i=0;i<n;i++)
        cout<<x[i]<<" ";
    cout<<"\n";
}
int main()
{
    int n;
    int i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>nuts[i];
    for(i=0;i<n;i++)
        cin>>bolts[i];
    match(0,n-1);
    print(nuts,n);
    print(bolts,n);
    return 0;
}

/*
6
@ # $ % ^ &
$ % & ^ @ #
*/

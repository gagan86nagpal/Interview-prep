#include <iostream>

using namespace std;
int a[200];
int temp[200];
int main()
{
    int n,d;
    cin>>n>>d;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        temp[i] = a[ (i+d)%n  ];
    for(int i=0;i<n;i++)
        a[i]=temp[i];
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    return 0;
}
/*
7 2
1 2 3 4 5 6 7
*/

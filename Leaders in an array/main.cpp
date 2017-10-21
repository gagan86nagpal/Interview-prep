#include <iostream>

using namespace std;
int a[1000];

// Taking maximum from right and comparing it with a[i] gives us answer
int main()
{
    int n;
    int i;
    int ma;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=n-1;i>=0;i--)
    {
        if(i==n-1)
            cout<<a[i]<< " ",ma=a[i];
        else
            if(a[i]>ma)
                cout<<a[i]<< " ",ma=a[i];
    }
    cout<<"\n";
    return 0;
}
/*
6
16 17 4 3 5 2
*/

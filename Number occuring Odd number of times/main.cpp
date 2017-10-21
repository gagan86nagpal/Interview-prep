#include <iostream>

using namespace std;
int a[300];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        int x=0;
        for(int i=0;i<n;i++)
            x^=a[i];
        cout<<x<<"\n";
    }
    return 0;
}

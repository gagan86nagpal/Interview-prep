#include <iostream>

using namespace std;
int a[1000];
int main()
{
    int n;
    int i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    int j;
    int maxL=0;
    int ma,mi;
    for(i=0;i<n;i++)
    {
        ma=a[i];
        mi=a[i];
        for(j=i;j<n;j++)
        {
            ma =max(ma,a[j]);
            mi =min(mi,a[j]);
            if(ma-mi==j-i)
                maxL = max(maxL,j-i+1);
        }
    }
    cout<<maxL<<"\n";
    return 0;
}

#include <iostream>

using namespace std;


int ans[1000];
int main()
{
    ans[1]=1;

    int i=1,j=1,k=1;
    int it,n;
    cin>>n;
    for(it=2;it<=n;it++)
    {
        int min_number = min( ans[i]*2,  min (ans[j]*3,ans[k]*5));
        ans[it]=min_number;
        if(min_number==ans[i]*2)
            i++;
        else if(min_number==ans[j]*3)
            j++;
        else
            k++;
        if(ans[it]==ans[it-1])  // avoid duplicity
            it--;
    }
    cout<<ans[n]<<"\n";
    return 0;
}

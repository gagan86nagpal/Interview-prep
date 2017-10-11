#include <iostream>

using namespace std;
int a[1000];

int largestContiguousSubarray(int n)
{
    int i;

    int max_sum=a[0];
    int prefix_sum=0;
    for(i=0;i<n;i++)
    {
            prefix_sum+=a[i];
            if(prefix_sum < 0) // doesn't include this guy
            {
                prefix_sum=0;
            }
            else
                max_sum=max(max_sum,prefix_sum);
    }
    return max_sum;
}
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    int ans = largestContiguousSubarray(n);
    cout<<ans<<"\n";
    return 0;
}

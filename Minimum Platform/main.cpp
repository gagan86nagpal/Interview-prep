#include <iostream>
#include <algorithm>
using namespace std;
int arr[5002],dep[5002];

int solve(int n)
{
    int platforms_needed=0;
    int max_platform = 0;
    int i=0,j=0;
    // i for arr array, j for dep array
    while(i<n) // since i will always be ahead of j, so we dont even need to check for j
    {
        if(arr[i] < dep[j]) // arrival happens
        {
            platforms_needed++;
            max_platform = max(max_platform,platforms_needed);
            i++;
        }
        else // departure happens
        {
            platforms_needed--;
            j++;
        }
    }
    return max_platform;
}
int main()
{
    int n;
    int i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>arr[i];
    for(i=0;i<n;i++)
        cin>>dep[i];
    sort(arr,arr+n);
    sort(dep,dep+n);
    int min_platforms = solve(n);
    cout<<min_platforms<<"\n";
    return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;
int a[100];

// Inorder to get lexicographically smallest permutation , we have to sort the array
// Else we can do this in linear time too
// Just by traversing even positions , move the max element among adjacent to i , to i
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(i=0;i+1<n;i+=2)
        swap(a[i],a[i+1]);
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    return 0;
}

#include <iostream>
#include <map>
using namespace std;
// Here elements can be non distinct
// So , we will create a map which will check if we have encountered unique elements or not
// If at any point , we have found out that an element is in already our map , then we can use
// max - min == j-i , so we won't consider that
map <int,int> m;
int a[100];
int largestSubArray(int n)
{
    int i,j;
    int maxL=0;
    for(i=0;i<n;i++)
    {
        m.clear();
        int mi = a[i];
        int ma=a[i];
        for(j=i;j<n;j++)
        {
            ma = max(ma,a[j]);
            mi = min(mi,a[j]);
            if(m.find(a[j])==m.end())// unique
            {
                m[a[j]]=1;
                if(ma-mi==j-i)
                    maxL = max(j-i+1,maxL);
            }
            else // duplicate , hence no need to extend and check further
                break;
        }
    }
    return maxL;
}
int main()
{
    int n,i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    int length = largestSubArray(n);
    cout<<length<<"\n";
    return 0;
}

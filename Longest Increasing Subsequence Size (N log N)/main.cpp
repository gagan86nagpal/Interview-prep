#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> a,tail1,tail2;
int lis(vector < int> & v,int flag)
{
    int length=0;
    for(unsigned i=0;i<a.size();i++)
    {
        if(length==0) // base case
        {
            length++;
            v.push_back(a[i]);
            continue;
        }
        // if new element is the smallest , then make the list of length 1 as
        // this new element
        if(a[i]<=v[0])
        {
            v[0]=a[i];
        }
        else if(a[i] > v.back()) // extend the biggest list
        {
            v.push_back(a[i]);
            length++;
        }
        else // find the list where this element should be added
        {
            int index;
            if(flag==0)
                index = upper_bound(v.begin(),v.end(),a[i])-v.begin();
            else
                index = lower_bound(v.begin(),v.end(),a[i])-v.begin();
            v[index]=a[i];
        }
    }
    return length;
}
int main()
{
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        a.push_back(x);
    }
    int ans1= lis(tail1,1);
    int ans2=lis(tail2,0);
    cout<<"LIS length:"<<ans1<<"\n";
    cout<<"LIS length:"<<ans2<<"\n";
    return 0;
}

/*
5
6 7 1 1 4 4
*/

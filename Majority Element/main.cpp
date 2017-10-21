#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map < int,int > m;
int a[102];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        m.clear();
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
        {
           cin>>a[i];
           m[a[i]]=m[a[i]]+1;
        }
        bool flag = false;
        int ele;
        for(int i=0;i<n;i++)
        {
            if(m[a[i]]>n/2)
            {
                ele =a[i];
                flag=true;
                break;
            }
        }
        if(!flag)
            cout<<"NO Majority Element";
        else
            cout<<ele;

        cout<<"\n";
    }
    return 0;
}

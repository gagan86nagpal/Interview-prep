#include <iostream>
#include <vector>
using namespace std;
int p[1000];

void printV(vector<int>x)
{
    for(auto y:x)
        cout<<y<<" ";
}
int matrixMul(vector<int> v)
{
    if(v.size()==2)
    {
        return 0;
    }
    int mi=1<<30;
    for(int i=0;i<(int)v.size()-2;i++)
    {
        int f=v[i],s=v[i+1],t=v[i+2];
        v.erase(v.begin()+i+1);
        mi=min(mi,p[f]*p[s]*p[t] +matrixMul(v) );
        v.insert(v.begin()+i+1,1+i);
    }
    return mi;
}
int main()
{
    int n;
    int i;
    cin>>n;
    vector <int>v;
    for(i=0;i<=n;i++)
        cin>>p[i];
    for(i=0;i<=n;i++)
        v.push_back(i);
    int cost=matrixMul(v);
    cout<<cost<<"\n";
    return 0;
}

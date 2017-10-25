#include <iostream>
#include <vector>
using namespace std;
vector <int> sequence;
void print(int n)
{
    for(int x: sequence)
        cout<<x<<" ";
    cout<<"\n";
}
void generateSequence(int i,int k,int n)
{
    if((int)sequence.size()==k)
    {
        print(n);
        return ;
    }
    if(i==n+1)
        return;

    sequence.push_back(i);
    generateSequence(i+1,k,n);
    sequence.pop_back();
    generateSequence(i+1,k,n);

}
int main()
{
    int n,k;
    cin>>k>>n;
    generateSequence(1,k,n);
    return 0;
}

#include <iostream>

using namespace std;


string a;
int diff()
{
    int ret=0;
    for(int i=0;i<(int)a.size();i++)
        if(a[i]=='1')
            ret++;

    return 2*ret-a.size();
}
void generatePermutations(int in,int n)
{
    if(in==n)
    {
        cout<<a<<"\n";
        return ;
    }
        a.push_back('1');
        generatePermutations(in+1,n);
        a.pop_back();

        if(diff()>0)
        {
            a.push_back('0');
            generatePermutations(in+1,n);
            a.pop_back();
        }

}
int main()
{
    int n;
    cin>>n;
    generatePermutations(0,n);
    return 0;
}

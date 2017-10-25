#include <iostream>

using namespace std;

bool isLessThan(int i,int j,string s)
{
    int n = s.size();
    int k = n;
    while(k--)
    {
        if(s[ i%n] > s[j%n])
            return false;
        else if(s[i%n] < s[j%n])
            return true;
        else
            i++,j++;
    }
    return true; // they are equal
}

int smallestRotation(string s)
{
    int n=s.size();
    int mi=0;
    int i;
    for(i=1;i<n;i++)
    {
        if(isLessThan(i,mi,s))
            mi=i;
    }
    return mi;
}
void print(int in,string s)
{
    int i;
    int n=s.size();
    for(i=0;i<n;i++)
        cout<<s[ (in+i)%n ];
    cout<<"\n";
}
int main()
{
   string s;
   cin>>s;
   int in;
   in = smallestRotation(s);
   print(in,s);
    return 0;
}

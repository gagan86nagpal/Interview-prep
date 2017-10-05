#include <iostream>

using namespace std;

int main()
{
    int t;
    string s;
    cin>>t;
    getline(cin,s);
    while(t--)
    {
        getline(cin,s);
        int i;
        for(i=0;i<(int)s.size();i++)
        {
            if(i==0|| (s[i-1]==' ') )
                if(s[i]>='a' && s[i]<='z')
                    s[i]=s[i]+'A'-'a';
        }
        cout<<s<<"\n";
    }
    return 0;
}

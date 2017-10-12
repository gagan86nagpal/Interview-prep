#include <iostream>

using namespace std;
int main() {


	int t,n;
	long long mod=1e9+7;
	long long a,b,c,i;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    a=1,b=1;
	    for(i=1;i<=n;i++)
	    {
	        c=a+b;
	        a=b;
	        b=c;
	        a%=mod;
	        b%=mod;
	        c%=mod;
	    }
	    cout<<c<<"\n";
	}
	return 0;
}

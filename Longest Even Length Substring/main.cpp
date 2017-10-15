#include <iostream>
using namespace std;
string a;


// Not a dp problem , since prefix sum is so common that general idea is prefix sum
// Really an exhaustive search with some efficient data structure problem

int prefix_sum[102];
int give_sum(int i,int j)
{
    return prefix_sum[j+1] - prefix_sum[i];
}
int main() {
	int t;
	int i, j;
	int ma=0;
	cin>>t;
	while(t--)
	{
	    ma=0;
	    cin>>a;
	    int n=a.size();
	    for(i=1;i<=n;i++)  // 1 based indexing
	        prefix_sum[i]=prefix_sum[i-1] +a[i-1]-'0';
	   for(i=0;i<n;i++)
	   {
	       for(j=i+1;j<n;j+=2)
	       {
	           int mid = (i+j)/2;
	           if(give_sum(i,mid) == give_sum(mid+1,j))
	           {
	                ma=max(ma,j-i+1);
	           }
	       }
	   }
	   cout<<ma<<"\n";
	}
	return 0;
}

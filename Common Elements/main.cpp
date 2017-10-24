#include <iostream>

using namespace std;
int a[1002],b[1002],c[1002];
int main()
{
   int n1,n2,n3;
   cin>>n1>>n2>>n3;
   int i,j,k;
   for(i=0;i<n1;i++)
    cin>>a[i];
   for(j=0;j<n2;j++)
    cin>>b[j];
   for(k=0;k<n3;k++)
    cin>>c[k];
    int cnt=0;
    i=j=k=0;
   while(i<n1 && j<n2&& k< n3)
   {
       if(a[i]==b[j] && b[j]==c[k])
       {
           cout<<a[i]<<" ";
           cnt++;
           i++;
           j++;
           k++;
       }
       else
       {
         if(a[i]< b[j] && a[i]<c[k])
            i++;
         else if(b[j]<c[k])
            j++;
         else
            k++;

       }
   }
   if(cnt==0)
    cout<<"-1\n";

    return 0;
}

/*
6 5 8
1 5 10 20 40 80
6 7 20 80 100
3 4 15 20 30 70 80 120
 */

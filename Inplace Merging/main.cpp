#include <iostream>

using namespace std;

int a[20];  // m+n
int b[10];  // n

void shift(int mn)
{
    int i=mn-1,j=mn-1;
    // j finds first occurence of -1 from right
    // i is first non -1 integer left to j
    while(i>=0 && j>=0)
    {
        while( j>=0&& a[j]!=-1)
        {
            j--;
        }
        i=min(i-1,j-1);  // for the first time , it takes j-1 , else always i-1
        while(i>=0&& a[i]==-1)
        {
            i--;
        }
        if(i!=-1 && j!=-1)  // if both are valid indices
            swap(a[i],a[j]);
        j--;
    }
}
void mergeArrays(int mn,int n)
{
    int i=n;
    int j = 0;
    int k=0;
    while(i<mn && j<n)
        if(a[i] > b[j])
            a[k++]=b[j++];
        else
            a[k++]=a[i++];
    while(i<mn)
        a[k++]=a[i++];
    while(j<n)
        a[k++]=b[j++];
}
void print(int x[],int s)
{
    int i;
    for(i=0;i<s;i++)
        cout<<x[i]<<" ";
    cout<<"\n";
}
int main()
{
    // negative elements to represent voids
    int mn;
    int n;
    cin>>mn;
    for(int i=0;i<mn;i++)
        cin>>a[i];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>b[i];

    // shift all elements to right to array a
    shift(mn);
    mergeArrays(mn,n);
    print(a,mn);
    return 0;
}

/*
7
2 -1 7 -1 -1 10 -1
4
5 8 12 14
*/

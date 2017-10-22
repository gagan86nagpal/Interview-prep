#include <iostream>

using namespace std;
int a[1001],b[1001];

/*
General idea is to discard some elements from two sub arrays that cannot contain the median.
Also , median of new subproblem will also be the median of our original subproblem.
Since initial length of two arrays are equal and we are discarding equal elements in each iteration. Hence , we are sure
that median of sub problem is the median of our original problem.
*/
double MedianOfSortedArray(int x[],int i,int j)
{
    int m = (i+j)/2;
    if( (j-i+1)%2 ==0 )// even
    {
       return ( x[m]+x[m+1] )/2.0;
    }
    else
    {
        return x[m];
    }
}

double findMedianOfTwoArray(int s1,int e1,int s2,int e2)
{
    int n = e1-s1+1;
    if(n==2)// base case of 4 elements
    {
        int s = a[s1]+a[e1]+b[s2]+b[e2];
        int mi  = min( min(a[s1],a[e1])  , min(b[s2],b[e2])  );
        int ma = max( max(a[s1],a[e1])  , max(b[s2],b[e2])   );
        return (s-mi-ma)/2.0;
    }
    double median1 = MedianOfSortedArray(a,s1,e1);
    double median2 = MedianOfSortedArray(b,s2,e2);
    if(n%2==0)
        n--;
    // make n odd by decrement by 1
    int elements_to_exclude = n/2;
    if(median1 > median2)
    {
        return findMedianOfTwoArray(s1+elements_to_exclude,e1,s2,e2-elements_to_exclude);
    }
    else
        return findMedianOfTwoArray(s1,e1-elements_to_exclude,s2+elements_to_exclude,e2);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n; // always even
        cin>>n;
        for(int i=0;i<n/2;i++)
            cin>>a[i];
        for(int i=0;i<n/2;i++)
            cin>>b[i];
        double median = findMedianOfTwoArray(0,n/2 -1,0,n/2-1);
        cout<<(int)median<<"\n";

    }
    return 0;
}
/*
3
4
56 67 30 79
4
78 89 67 76
5
90 100 78 89 67
*/

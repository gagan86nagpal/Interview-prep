#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct box
{
    int l,b,h;
    box()
    {

    }
    box(int l,int b,int h)
    {
        this->b=b;
        this->l=l;
        this->h=h;
    }
    void print()
    {
        cout<<l<<","<<b<<","<<h<<"\n";
    }
};
bool comp(box b1,box b2) // true if b1 < b2
{
    int ma1=max(b1.l,b1.b);
    int ma2=max(b2.l,b2.b);
    int mi1=min(b1.l,b1.b);
    int mi2=min(b2.l,b2.b);
    return (ma2 > ma1) || (mi2>mi1 );
}
bool isSmall(box b1,box b2) // true if b1 < b2
{
    int ma1=max(b1.l,b1.b);
    int ma2=max(b2.l,b2.b);
    int mi1=min(b1.l,b1.b);
    int mi2=min(b2.l,b2.b);
    return (ma2 > ma1) && (mi2>mi1 );
}
vector < box> boxes;
vector <int> dp;
int main()
{
    int n,i,j;
    int t;
    cin>>t;
    while(t--)
    {
        dp.clear();
        boxes.clear();
        cin>>n;
        for(i=0;i<n;i++)
        {
            int l,b,h;
            cin>>l>>b>>h;
            boxes.push_back(box(l,b,h)) ;
            boxes.push_back( box(l,h,b) ) ;
            boxes.push_back( box(b,h,l) );
        }
        dp=vector<int>(3*n,0);
        sort(boxes.begin(),boxes.end(),comp);
            for(box b: boxes)
        b.print();
        dp[0]=boxes[0].h;
        for(i=1;i<(int)boxes.size();i++)
        {
            for(j=0;j<i;j++)
            {
                if(isSmall(boxes[j],boxes[i]))
                    dp[i]=max(dp[j]+boxes[i].h,dp[i]);
            }
        }
        int max_height=0;
        for(i=0;i<(int)boxes.size();i++)
                max_height=max(max_height,dp[i]);
        cout<<max_height<<"\n";
    }


    return 0;
}

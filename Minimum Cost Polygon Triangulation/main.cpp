#include <iostream>
#include <cmath>
using namespace std;

/*
Most tricky part in this question is formulation of our recursive function in its basic form.
Program to enumerate all the possible triangulations is difficult as it is hard to
think like "in order to make a triangulation , you can fix two end points and choose one point in between them.
After choosing , we again have two end points and similar recursive structure.
Even After having this recursive function , it is hard to convince ourselves that this does considers all
possible triangulations.
*/
struct Points
{
    double x,y;

    Points(double x,double y)
    {
        this->x=x;
        this->y=y;
    }
    Points()
    {

    }
};
Points p[1000];

double dp[1000][1000];
void init(int n)
{
    int i,j;
    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            dp[i][j]=-1;
}
double dist(Points p1,Points p2)
{

    double ret= sqrt((p1.x-p2.x )*(p1.x-p2.x )  + (p1.y-p2.y)*(p1.y-p2.y) );
    return ret;
}

double cost(Points p1, Points p2, Points p3)
{
    return dist(p1,p2) + dist(p2,p3) + dist(p1,p3);
}

double minimumCostTriangulation(int i,int j)
{
    if(i+2 > j)
        return 0;
    int k;
    if(dp[i][j]!=-1)
        return dp[i][j];
    double mini=1<<30;
    for(k=i+1 ; k< j ;k++)  // Make a triangle with points i,j,k
    {
        mini = min(mini,cost(p[i],p[j],p[k])  +  minimumCostTriangulation(i,k) +   minimumCostTriangulation(k,j));
    }
    return dp[i][j]= mini;
}
int main()
{
    int n,i;
    double x,y;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x>>y;
        p[i]=Points(x,y);
    }
    init(n);
    double minCost = minimumCostTriangulation(1,n);
    cout<<minCost<<"\n";
    return 0;
}


/*
5
0 0
1 0
2 1
1 2
0 2
*/

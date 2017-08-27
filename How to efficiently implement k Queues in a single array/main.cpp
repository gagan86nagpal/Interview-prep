#include <iostream>

using namespace std;

const int max_n=10000;
const int max_k=10000;
int arr[max_n];

// to keep track of fronts of queues
int fronts[max_k];

// to keep track of rears of queues
int rears[max_k];
// Free cells can be visualized as stacks , freefront is top of the stack
int freeFront;
// it points to next member, -1 if it the last member
int nexts[max_n];

// initializes all queues to be empty and space as free space
void init(int n , int k)
{
    int i;
    for(i=0;i<k;i++)
        fronts[i]=-1;
    for(i=0;i<k;i++)
        rears[i]=-1;
    freeFront=0;
    for(i=0;i<n-1;i++)
    {
        nexts[i]=i+1;
    }
    nexts[n-1]=-1;
}
void enqueue(int qn,int x)
{
    if(freeFront==-1)
    {
        cout<<"No Sapce is empty\n";
        return;
    }
    if(fronts[qn]==-1)  // queue is empty, update both rear and front
    {
        cout<<"queue is empty\n";
        fronts[qn]=freeFront;

        rears[qn]=freeFront;
        freeFront=nexts[freeFront];
        nexts[rears[qn]]=-1;
        arr[rears[qn]]=x;
        return;
    }
    nexts[rears[qn]]=freeFront;
    rears[qn]=freeFront;
    freeFront=nexts[freeFront];
    nexts[rears[qn]]=-1;
    arr[rears[qn]]=x;
}
int dequeue(int qn)
{
    if(fronts[qn]==-1)
    {
        cout<<"Queue:"<<qn<<"is empty\n";
        return -1;
    }
    int temp  = fronts[qn];
    fronts[qn]=nexts[temp];
    nexts[temp]=freeFront;
    freeFront=temp;
    return arr[temp];
}
void printStaus(int n,int k)
{
    int i,j;
    cout<<"Free Cells: ";
    j=freeFront;
    while(j!=-1)
    {
        cout<<j<<" ";
        j=nexts[j];
    }
    cout<<"\n";
    for(i=0;i<k;i++)
    {
        cout<<"Queue "<<i<<":";
        j=fronts[i];
        while(j!=-1)
        {
            cout<<arr[j]<<" ";
            j=nexts[j];
        }
        cout<<"\n";
    }
}
int main()
{
    int n,k;
    n=10;  // total capacity of n elements
    k=4;  // total k queues

    init(n,k);  // initialize our data structure
    printStaus(n,k);
    enqueue(0,3);
    printStaus(n,k);
    enqueue(0,2);
    printStaus(n,k);
    enqueue(1,1);
    printStaus(n,k);
    enqueue(2,11);
    printStaus(n,k);
    enqueue(3,12);
    printStaus(n,k);
    enqueue(3,2);
    printStaus(n,k);
    enqueue(3,13);
    printStaus(n,k);
    enqueue(3,3);
    printStaus(n,k);
    enqueue(3,3);
    printStaus(n,k);
    enqueue(3,4);
    printStaus(n,k);
    enqueue(2,5);
    printStaus(n,k);
    dequeue(3);
    printStaus(n,k);
    dequeue(3);
    printStaus(n,k);
    dequeue(1);
    printStaus(n,k);
    dequeue(1);
    printStaus(n,k);
    enqueue(1,2);
    printStaus(n,k);
    return 0;
}

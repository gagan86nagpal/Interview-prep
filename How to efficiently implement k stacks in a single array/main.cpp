#include <iostream>

using namespace std;
#define max 10
int arr[10000];  // it actually store values
int top[1000]; // tells us the index of top of ith stack
int down[10000];  // points to 1 element down in the stack (it stores index)
int chunkTOp; // has index of stack which points to free chunks of memory present

void init(int k)
{
    chunkTOp=0;// free stack's top is 0 initially
    int i;
    for(i=0;i<=max-2;i++)
        down[i]=i+1;
    down[max-1]=-1;  // stack's bottom
    for(i=1;i<=k;i++)
        top[i]=-1;   // K stack are empty initially

    // arr doesnot hold any value so , no need to initialize it
}
void printStacks(int k)
{
    int i,j;
    cout<<"Free Indices:";
    j=chunkTOp;
    while(j!=-1)
    {
        cout<<j<<" ";
        j=down[j];
    }
    cout<<"\n";
    for(i=1;i<=k;i++)
    {
        cout<<"Stack "<<i<<": ";
        j=top[i];
        while(j!=-1)
        {
            cout<<arr[j]<<" ";
            j=down[j];
        }
        cout<<"\n";
    }

}
void push(int StackNumber,int x)
{
    if(chunkTOp==-1)
    {
        cout<<"No Space Available\n";
    }
    else
    {
        int index=chunkTOp;
        chunkTOp=down[chunkTOp];
        arr[index]=x;
        if(top[StackNumber]==-1)
        {
            top[StackNumber]=index;
            down[index]=-1;
        }
        else
        {
            down[index]=top[StackNumber];
            top[StackNumber]=index;
        }
    }
}
int pop(int StackNumber)
{
    int ret=2147483647;
    if(top[StackNumber]==-1)
    {
        cout<<"Stack "<<StackNumber<<" is empty\n";
    }
    else
    {
        int index=top[StackNumber];
        ret =arr[index];
        top[StackNumber]=down[index];
        down[index]=chunkTOp;
        chunkTOp=index;
    }
    return ret;
}
int main()
{
    int k;
    k=3;
    init(k);
    printStacks(k);
    push(1,5);
    printStacks(k);
    push(2,5);
    push(2,6);
    push(2,2);
    push(2,5);
    push(2,1);
    printStacks(k);
    cout<<pop(2)<<"\n";
    printStacks(k);
    push(3,4);
    push(3,10);
    push(3,5);
    push(3,4);
    push(1,51);
    push(1,3);
    printStacks(k);
    cout<<pop(1)<<"\n";
    cout<<pop(1)<<"\n";
    printStacks(k);
    cout<<pop(1)<<"\n";
    printStacks(k);

    return 0;
}

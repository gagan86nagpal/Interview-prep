#include <iostream>
#include <string>
using namespace std;
class Queue
{
private:
    static const int capacity=100;
    int r=-1;
    int f=-1;
    string a[capacity];
public:
    string rear()
    {
        if(r!=-1)
            return a[r];
        else
            cout<<"Queue is Empty\n";
        return "-1";
    }
    string front()
    {
        if(f!=-1)
            return a[f];
        else
            cout<<"Queue is Empty\n";
        return "-1";
    }
    void enqueue(string x)
    {
        if(f==r+1 ||(f==0 && r==capacity-1) )
            cout<<"Queue is full\n";
        else
        {
            r++;
            if(r==capacity)
                r=0;
            a[r]=x;
            if(f==-1)
                f=0;
        }
    }
    string dequeue()
    {
        if(f==r&&f==-1)
            cout<<"Queue is empty\n";
        string ret;
        ret=a[f];
        if(f==r)
        {
            f=-1;
            r=-1;
            return ret;
        }
        f++;
        if(f==capacity)
            f=0;
        return ret;
    }
    void print()
    {
        cout<<"front:"<<f<<", rear:"<<r<<"\n";
        if(f==r &&(f==-1 ) )
        {
            cout<<"Queue is empty";
        }
        else
        {
            int temp=f;
            while(temp!=r)
            {
                cout<<a[temp]<<" ";
                temp++;
                if(temp==capacity)
                    temp=0;
            }
            cout<<a[temp]<<" ";
        }
        cout<<"\n";
    }
};
void printBinary(int n)
{
    Queue q;
    q.enqueue("1");
    string s1,s2;
    while(n--)
    {
        s1=q.dequeue();
        s2=s1;
        cout<<s1<<"\n";
        q.enqueue(s1.append("0"));
        q.enqueue(s2.append("1"));
    }

}
int main()
{
    int n;
    cin>>n;
    printBinary(n);
    return 0;
}

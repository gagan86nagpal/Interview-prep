#include <iostream>

using namespace std;
class twoStacks
{
private:
    static const int capacity=10;
    int top1=-1,top2=capacity;
    int a[capacity];

public:
    void push1(int x)
    {
       if(top1+1<top2)
           a[++top1]=x;
       else
           cout<<"No Space in array left\n";
    }
    void push2(int x)
    {
        if(top1+1<top2)
           a[--top2]=x;
       else
           cout<<"No Space in array left\n";
    }
    int pop1()
    {
        if(top1==-1)
            cout<<"Stack1 is empty\n";
        else
            return a[top1--];
    }
    int pop2()
    {
        if(top2==capacity)
            cout<<"Stack2 is empty\n";
        else
            return a[top2++];
    }
    bool is1empty()
    {
        return top1==-1;
    }
    bool is2empty()
    {
        return top2==capacity;
    }
    void print()
    {
        int temp=top1;
        cout<<"Stack1:";
        while(temp>=0)
            cout<<a[temp--]<<" ";
        cout<<"\n";
        cout<<"Stack2:";
        temp=top2;
        while(temp<capacity)
            cout<<a[temp++]<<" ";
        cout<<"\n";
    }
};
int main()
{
    twoStacks s;
    s.push1(1);
    s.push1(2);
    s.push1(4);
    s.push2(3);
    s.push2(6);
    s.push2(7);
    s.push2(1);
    s.push2(25);
    s.push2(4);
    s.print();
    s.pop1();
    s.print();
    s.pop1();
    s.print();
    s.pop1();
    s.print();
    s.pop1();
    s.print();
    s.push2(3);
    s.push2(6);
    s.pop2();
    s.push2(25);
    s.push2(4);
    s.print();
    s.push1(4);
    s.push1(4);
    s.print();
    return 0;
}

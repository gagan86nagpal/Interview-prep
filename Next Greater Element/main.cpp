#include <iostream>

using namespace std;

/*
Given an array, print the Next Greater Element (NGE) for every element.
The Next greater Element for an element x is the first greater element on the right side of x in array.
Elements for which no greater element exist, consider next greater element as -1.
*/

/*
Solution is to traverse from right and push only those elements which are answer to some elements.
Now at each point we can check the just right element and also the elements in the stack as these
elements can only contribute to answer.
Elements which are never pushed to stack would never be an answer to some node.
In worst case , all elements are pushed and popped once , giving a time complexity of O(n)
*/
int input[100];
int output[100];
class Stack{
private:
    int top=-1;
    static const int max=1000;
    int a[1000];
public:
    void push(int c)
    {
        a[++top]=c;
    }
    int pop()
    {
        return a[top--];
    }
    bool isEmpty()
    {
        return top==-1;
    }
    int getTop()
    {
        return a[top];
    }
};

int main()
{
    int n;
    int i;
    Stack st;
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>input[i];
    for(i=n;i>=1;i--)
    {
        if(i==n)  // rightmost
            output[i]=-1;
        else if(input[i]<input[i+1]) // right element is greater
        {
            output[i]=input[i+1];
            st.push(input[i+1]);
        }
        else  // answer may be on way right
        {
            while(!st.isEmpty()&&st.getTop() < input[i])
                st.pop();
            if(st.isEmpty())  // no greater element exists
            {
                output[i]=-1;
                st.push(input[i]);
            }
            else
            {
                output[i]=st.getTop();
            }
        }
    }
    for(i=1;i<=n;i++)
        cout<<output[i]<<" ";
    cout<<"\n";
    return 0;
}

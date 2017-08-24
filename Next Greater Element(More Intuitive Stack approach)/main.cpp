#include <iostream>

using namespace std;

/*
Given an array, print the Next Greater Element (NGE) for every element.
The Next greater Element for an element x is the first greater element on the right side of x in array.
Elements for which no greater element exist, consider next greater element as -1.
*/

/*
We will push those elements to stack whose answer is yet not known.
This automatically makes element in stack to go in decreasing order(from top to bottom).
Whenever a bigger element comes , We just check how many elements in stack are smaller than bigger element,
we assign answer of smaller elements to this bigger number and push it back to stack as it's answer is
not known.
We will push index of elements in the stack, since we have to update our output[] array
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
        st.push(1); // pushing index of 1st element to stack as it's answer is not known
    for(i=2;i<=n;i++)
    {
        while(!st.isEmpty()&&input[i]>input[st.getTop()])  // answer of all smaller elements is a[i]
        {
            output[st.getTop()]=input[i];
            st.pop();
        }
        st.push(i); // answer of a[i] is not known yet
    }
    while(!st.isEmpty())  // Rest of the elements don't have any number greater than themselves on the right
        output[st.pop()]=-1;
    for(i=1;i<=n;i++)
        cout<<output[i]<<" ";
    cout<<"\n";
    return 0;
}

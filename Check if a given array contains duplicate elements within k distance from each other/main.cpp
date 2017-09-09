#include <iostream>

using namespace std;
// Idea is to create a hash table of size k+1
// initially insert first k+1 elements in the hashtable
// Now, for each element check if there are more than 1 occurences are present or not
// Also , while iterating keep updating your hash table

int hashTable[100];
int main()
{
    bool flag=false;
    int k=2;
    int a[]={10, 5, 10, 6, 4, 5, 6};
    int n=sizeof(a)/sizeof(a[0]);
    int i;
    for(i=0;i<=k;i++) // k+1 times
        hashTable[a[i]]++;
    for(i=0;i<n-k;i++)
    {
        if(i==0)
        {
            if(hashTable[a[i]]>=2)
            {
                flag=true;
                break;
            }
        }
        else
        {
            hashTable[a[i-1]]--;  // deleting previous element
            hashTable[a[i+k]]++;  // inserting k ahead element
            if(hashTable[a[i]]>=2)  // check for two occurrences
            {
                flag=true;
                break;
            }
        }
    }
    if(flag)
        cout<<"True\n";
    else
        cout<<"False\n";

    return 0;
}

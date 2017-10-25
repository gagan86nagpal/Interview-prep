#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// idea is to maintain different array of strings which have indexes as well
// Sorting individual strings and then the  entire will make panagrams come together

vector <string> input;
vector < pair <string,int> > aux;
int main()
{
    int n;
    string s;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        input.push_back(s);
        sort(s.begin(),s.end());
        aux.push_back(make_pair(s,i));
    }

    sort(aux.begin(),aux.end());
    cout<<input[aux[0].second]<<" ";
    for(int i=1;i<n;i++)
    {
        if(aux[i].first==aux[i-1].first)
            cout<<input[aux[i].second]<<" ";
        else
            cout<<"\n"<<input[aux[i].second]<<" ";
    }
    cout<<"\n";
    return 0;
}
/*
5
geeksquiz
geeksforgeeks
abcd
forgeeksgeeks
zuiqkeegs
*/

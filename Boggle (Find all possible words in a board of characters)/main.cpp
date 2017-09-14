#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
Given a dictionary, a method to do lookup in dictionary and a M x N board where every cell has one character.
Find all possible words that can be formed by a sequence of adjacent characters.
Note that we can move to any of 8 adjacent characters, but a word should not have multiple instances of same cell.
*/

// Very unoptimized solution
// Please do not think about time complexity , at least find a solution


// Idea is to make a DFS call from each and every cell in matrix , while making a dfs call check all the words in the dictionary
// Even for a single dfs call , (time = exponential * length of dictionary * (average string length in dictionary )
// We are totoal m*n dfs calls
// May god forgive us

int cnt=0;  // just to see , how worse this algo is
const int m=3,n=3;
char boggle[m][n] =     {{'G','I','Z'},
                         {'U','E','K'},
                         {'Q','S','E'}};

vector<string> dictionary{"GEEKS", "FOR", "QUIZ", "GO"};
int vis[m][n];
bool is_word_in_dictionary(string &s)
{
    int i;
    for(i=0;i<dictionary.size();i++)
    {
        if(s==(dictionary[i]))
            return true;
    }
    return false;
}

void dfs(int i,int j,string &word)
{
    cnt++;
    if(vis[i][j])  // already visited
        return;
    vis[i][j]=1;
    word.push_back(boggle[i][j]);
   // cout<<word<<"\n";     // uncomment this to see , the wrath of this algorithm
    if(is_word_in_dictionary(word))
        cout<<word<<"\n";
    int r,c;
    for(r=i-1 ; r<=i+1; r++)
        for(c=j-1; c<=j+1;c++)
            if(r>=0 && c>=0 && r<m &&c<n)
                dfs(r,c,word);
    word.pop_back();
    vis[i][j]=0;
}

void make_all_calls()
{
    string word="";
    int i,j;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            dfs(i,j,word);
}
int main()
{
    make_all_calls();
    cout<<"Iterations: "<<cnt<<"\n";
    return 0;
}

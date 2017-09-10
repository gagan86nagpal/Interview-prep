#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <set>
using namespace std;

// Idea is to first find out the starting point , then traverse the whole itinerary .
// Starting point will be the point which is present as a key in map but not as a value
// So , we are first creating a set of keys
// Now , for each value in map , we are deleting keys from set
// Remaining element in set is the Starting point
int main()
{
    map <string,string> m;
    set <string > s;
    m.insert(make_pair("Chennai","Banglore"));
    m.insert(make_pair("Bombay","Delhi"));
    m.insert(make_pair("Goa","Chennai"));
    m.insert(make_pair("Delhi","Goa"));

    string start="";
    for(pair <string,string> p:m)
        s.insert(p.first);

    for(pair <string,string> p : m)
        if(s.find(p.second)!=s.end()) // found
            s.erase(p.second);

   start=*s.begin();
   while(m.find(start)!=m.end())
   {
       cout<<start<<" -> "<<m[start]<<", ";
       start=m[start];
   }
    return 0;
}

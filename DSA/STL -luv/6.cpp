// Unordered map
#include <bits/stdc++.h>
using namespace std;
void print(auto m)
{
    for (auto map_pair : m)
    {
        // Tc = O(1)
        cout << map_pair.first << " " << map_pair.second << endl;
    }
}
int main()
{
    unordered_map<int, string> m;
    // Insertion in map
    m[1] = "abc"; // Tc=O(1) , n= size if we insert string in key then tc=O(1) as before storing it will compare itself to other
    m[5] = "cdc";
    m[3] = "acd";
    m.insert({4, "afg"});
    // Automatically stored in sorted order (lexographically) therefore normal map
    print(m);
    cout << "Size = " << m.size() << endl;
    auto it = m.find(5);
    // this will return iterator
    // if key =3 is present it will return its iterator else return m.end()
    if (it == m.end())
    {
        cout << "No value" << endl;
    }
    else
    {
        cout << it->first << " " << it->second << "  ";
    }
    // Using erase to delete element from map
    m.erase(3);
    if (it != m.end())
        m.erase(it);
    // since m.end() is just a way to represent it doe not exist hence cant be erased    cout << endl;
    cout << endl;
    print(m);
    cout << endl;
    m.clear();
    print(m);
    // In multimap we can store multiple value against a key but it is not used insted map<int,vector> can be used
    return 0;
}
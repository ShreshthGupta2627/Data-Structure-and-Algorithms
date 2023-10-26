// Maps in stl
#include <bits/stdc++.h>
using namespace std;
void print(auto m)
{
    for (auto map_pair : m)
    {
        // Tc = O(log n)
        cout << map_pair.first << " " << map_pair.second << endl;
    }
}
int main()
{
    map<int, string> m;
    // Insertion in map
    m[1] = "abc"; // Tc=O(log n) , n= size if we insert string in key then tc=O(n) as before storing it will compare itself to other
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
    // Hash map
    map<int, int> m5;
    int p;
    cin >> p;
    for (int i = 0; i < p; i++)
    {
        int tp;
        cin >> tp;
        m5[tp]++;
    }
    print(m5);
    return 0;
}
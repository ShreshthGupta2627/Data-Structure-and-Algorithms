// All about set
#include <bits/stdc++.h>
using namespace std;
void print1(multiset<string> &s)
{
    for (string value : s)
    {
        cout << value << " ";
    }
    cout << endl;
    // One more way to print
    //  for (auto it = s.begin(); it != s.end(); it++)
    //  {
    //      cout << *it << " ";
    //  }
    //  cout << endl;
}
void print(set<string> &s)
{
    for (string value : s)
    {
        cout << value << " ";
    }
    cout << endl;
}
int main()
{
    set<string> s;
    // Use red black tree for implementation
    s.insert("abc");
    // Set dont store same elements
    s.insert("abc");
    s.insert("zsdf");
    s.insert("bcd");
    // Finding element  in set if fount give it iterator else give iterator of s.end()
    auto it = s.find("abc");
    if (it != s.end())
        cout << *it << endl;
    print(s);
    // s.erase("abc"); -> this is also valid
    s.erase(it);
    print(s);

    // Unordered set
    unordered_set<int> s1;
    // tc for insertion and find is O(1)

    // Multi set
    multiset<string> s5;
    // Almost all operation are tc=O(logn)
    s5.insert("abc");
    s5.insert("zsdf");
    s5.insert("bcd");
    s5.insert("bcd");
    s5.insert("abc");
    print1(s5);
    // If element are duplicate then s.find("abc") will return iterator to first abc
    auto it2 = s5.find("abc");
    if (it2 != s5.end())
    {
        s5.erase(it);
        // By using iterator we delete only the pointed one if we directly use s.erase("") it will return all copies
    }
    print1(s5);
    s5.erase("bcd");
    // This will delete all iterator who is pointing to "bcd"
    print1(s5);
    return 0;
}
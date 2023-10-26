// Question on unordered set
// Given N string and Q quaries. In each query you are given a string print yes if string is present else print no, N<=10^6 , |S|<=100 , Q<=10^6
#include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_set<string> s;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s1;
        cin >> s1;
        s.insert(s1);
    }
    int q;
    cin >> q;
    while (q--)
    {
        string str;
        cin >> str;
        if (s.find(str) == s.end())
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    // All operation on insertion or find is O(1)  , so use unordered set
    return 0;
}
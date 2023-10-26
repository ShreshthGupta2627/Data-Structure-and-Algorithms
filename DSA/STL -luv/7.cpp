// Question on unordered map
// Given N strings and Q quaries in each quary you are given a string print their frequency N<=10^6 ,|S|<=100 , Q<=10^6
#include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<string, int> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        m[s] = m[s] + 1;
        // since it is int it will auto initialize to 0
    }
    int q;
    cin >> q;
    while (q--)
    {
        string s;
        cin >> s;
        cout << m[s] << endl;
    }
    // print(m);
    return 0;
}
// Qestion on map
// Given N strings print unique stringsin lexographical order with their frequency N<=10^5 ,|S|<=100
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
    map<string, int> m;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        m[s] = m[s] + 1;
        // since it is int it will auto initialize to 0
    }
    print(m);
    return 0;
}
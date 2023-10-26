// Storing graphs in list
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // n --> nodes  m --> edges
    int n, m;
    cin >> n >> m;
    // Adding 1 to covert it to 1 based indexing for zero base take n instead
    vector<int> adj[n + 1];
    // Graph is stored above and its a less costilier process it take 2*E space
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        // in case of directed graph u-- > v means that only u-- > v :. below line will not be there and space reduced to E
        adj[v].push_back(u);
    }
    return 0;
}
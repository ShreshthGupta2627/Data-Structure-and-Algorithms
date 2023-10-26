// Storing graphs in adjacency matrix
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // n --> nodes  m --> edges
    int n, m;
    cin >> n >> m;
    // Adding 1 to covert it to 1 based indexing
    int adj[n + 1][m + 1] = {{0, 0}};
    // Graph is stored above but its a costlt process it takr N*N space
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    return 0;
}
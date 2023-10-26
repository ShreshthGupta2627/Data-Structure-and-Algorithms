// Articulation Point in Graph
/*Given an undirected connected graph with V vertices and adjacency list adj. You are required to find all the vertices removing which (and edges through it) disconnect the graph into 2 or more components.
Note: Indexing is zero-based i.e nodes numbering from (0 to V-1). There might be loops present in the graph.*/

#include <bits/stdc++.h>
using namespace std;

void ArticulationPoint(int n, vector<vector<int>> &adj)
{
}
int main()
{
    int n = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 4}, {2, 4}, {2, 3}, {3, 4}};

    vector<vector<int>> adj(n);
    for (auto it : edges)
    {
        int u = it[0], v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    return 0;
}
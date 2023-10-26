// Minimum Spanning Tree - Prims algorithm

#include <bits/stdc++.h>
using namespace std;
void prims(vector<vector<pair<int, int>>> &adj)
{
    int n = adj.size();
    vector<int> vis(n, 0);

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    vector<pair<int, int>> mst;
    int TotalWt = 0;
    //{Wt,{node,par}
    pq.push({0, {0, -1}});
    // E
    while (!pq.empty())
    {
        auto it = pq.top();
        pq.pop();
        // log E => total = E log E
        int wt = it.first;
        int node = it.second.first;
        int par = it.second.second;
        if (!vis[node])
        {
            if (par != -1)
            {
                mst.push_back({par, node});
            }
            vis[node] = 1;
            TotalWt += wt;
            int parr = node;
            // total : E log E
            for (auto &neig : adj[node])
            {
                int adjNode = neig.first;
                int adjWt = neig.second;
                if (!vis[adjNode])
                {
                    pq.push({adjWt, {adjNode, parr}});
                }
            }
        }
    }
    // Total Tc: E log E
    cout << TotalWt << endl;

    cout << "MST is :" << endl;

    for (auto &it : mst)
    {
        cout << it.first << " -> " << it.second << endl;
    }
}
void addEdge(vector<vector<pair<int, int>>> &adj, int u, int v, int wt)
{
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
}
int main()
{
    vector<vector<pair<int, int>>> adj(8);
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 3, 6);
    addEdge(adj, 1, 2, 3);
    addEdge(adj, 1, 3, 8);
    addEdge(adj, 1, 4, 5);
    addEdge(adj, 2, 4, 7);
    prims(adj);

    // Tc : O(E)
    return 0;
}
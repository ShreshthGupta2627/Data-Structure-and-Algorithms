// Shortest path in undirected graph with unit weight
/*Given a undirected unit edge weight graph and a source you need to give min distance of all nodes form source if no path btwn them put -1*/
#include <bits/stdc++.h>
using namespace std;
void bfs(int src, vector<vector<int>> &adj)
{
    int n = adj.size();
    queue<int> q;
    vector<int> dist(n, 1e9);
    dist[src] = 0;
    q.push(src);
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        for (auto &it : adj[curr])
        {
            if (dist[it] > dist[curr] + 1)
            {
                dist[it] = dist[curr] + 1;
                q.push(it);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dist[i] << endl;
    }
}
void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{
    vector<vector<int>> adj(9);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 3);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 6);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 6);
    addEdge(adj, 6, 7);
    addEdge(adj, 6, 8);
    addEdge(adj, 7, 8);
    bfs(0, adj);
    return 0;
}
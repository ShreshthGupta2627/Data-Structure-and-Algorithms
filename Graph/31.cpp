// Shortest path in an undirected weighted graph
/*You are given an Undirected Graph having unit weight, Find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.
 */
#include <bits/stdc++.h>
using namespace std;

void Dijakstra(int src, vector<vector<pair<int, int>>> adj)
{
    int n = adj.size();
    // MinHeap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, 1e9);
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
    }
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();

        int wt = curr.first;
        int node = curr.second;

        for (auto &it : adj[node])
        {
            if (dist[it.first] > it.second + wt)
            {
                dist[it.first] = it.second + wt;
                pq.push({dist[it.first], it.first});
                parent[it.first] = node;
            }
        }
    }

    vector<int> ans;
    int node = n - 1;
    while (parent[node] != node)
    {
        ans.push_back(node);
        node = parent[node];
    }
    ans.push_back(1);

    for (auto &it : ans)
    {
        cout << " " << it;
    }
    cout << endl;
}

void addEdge(vector<vector<pair<int, int>>> &adj, int u, pair<int, int> v)
{
    adj[u].push_back(v);
    adj[v.first].push_back({u, v.second});
}
int main()
{
    vector<vector<pair<int, int>>> adj(6);
    addEdge(adj, 1, {2, 2});
    addEdge(adj, 1, {4, 1});
    addEdge(adj, 2, {5, 3});
    addEdge(adj, 2, {3, 4});
    addEdge(adj, 3, {4, 3});
    addEdge(adj, 3, {5, 1});

    Dijakstra(1, adj);
    return 0;
}
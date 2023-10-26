// Shortest path in directed acyclic graph
/*Given a Directed Acyclic Graph of N vertices from 0 to N-1 and a 2D Integer array(or vector) edges[ ][ ] of length M, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i, 0<=i
Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.*/

#include <bits/stdc++.h>
using namespace std;
// Using bfs
void bfs(vector<vector<pair<int, int>>> &adj)
{
    int n = adj.size();
    queue<int> q;

    vector<int> indegree(n, 0);
    vector<int> topoSort;
    for (int i = 0; i < n; i++)
    {
        for (auto &neig : adj[i])
        {
            indegree[neig.first]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        topoSort.push_back(curr);
        for (auto &it : adj[curr])
        {
            indegree[it.first]--;
            if (indegree[it.first] == 0)
            {
                q.push(it.first);
            }
        }
    }

    vector<int> dist(n, 1e9);
    dist[0] = 0;
    for (int i = 0; i < topoSort.size(); i++)
    {
        for (auto &it : adj[topoSort[i]])
        {
            if (dist[topoSort[i]] + it.second < dist[it.first])
            {
                dist[it.first] = dist[topoSort[i]] + it.second;
            }
        }
    }

    for (int i = 0; i < topoSort.size(); i++)
    {
        cout << i << " " << dist[i] << endl;
    }
}

// Using dfs
void topo(int node, vector<vector<pair<int, int>>> &adj, vector<int> &vis, stack<int> &st)
{
    vis[node] = 1;
    for (auto &it : adj[node])
    {
        int curr = it.first;
        if (!vis[curr])
        {
            topo(curr, adj, vis, st);
        }
    }
    st.push(node);
}

void dfs(int src, vector<vector<pair<int, int>>> &adj)
{
    int n = adj.size();
    vector<int> vis(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            topo(i, adj, vis, st);
        }
    }

    vector<int> dist(n, 1e9);
    dist[src] = 0;
    while (!st.empty())
    {
        int curr = st.top();
        st.pop();

        for (auto &it : adj[curr])
        {
            int v = it.first;
            int wt = it.second;

            // cout << "%" << endl;
            if (dist[curr] + wt < dist[v])
            {
                dist[v] = dist[curr] + wt;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << dist[i] << endl;
    }
}
void addEdge(vector<vector<pair<int, int>>> &adj, int u, pair<int, int> v)
{
    adj[u].push_back(v);
}
int main()
{
    int n = 7;
    vector<vector<pair<int, int>>> adj(n);
    addEdge(adj, 6, {4, 2});
    addEdge(adj, 6, {5, 3});
    addEdge(adj, 5, {4, 1});
    addEdge(adj, 4, {0, 3});
    addEdge(adj, 4, {2, 1});
    addEdge(adj, 2, {3, 3});
    addEdge(adj, 1, {3, 1});
    addEdge(adj, 0, {1, 2});
    // dfs(0, adj);
    bfs(adj);
    return 0;
}
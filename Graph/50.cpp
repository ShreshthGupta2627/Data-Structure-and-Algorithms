// Bridges in graph
/*There are n servers numbered from 0 to n – 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.
A critical connection is a connection that, if removed, will make some servers unable to reach some other servers.
Return all critical connections in the network in any order.
Note: Here servers mean the nodes of the graph. The problem statement is taken from leetcode.*/

#include <bits/stdc++.h>
using namespace std;
int timer = 1;
void dfs(int node, int parent, vector<int> &vis, vector<vector<int>> &adj, vector<int> &time, vector<int> &low, vector<pair<int, int>> &bridge)
{
    vis[node] = 1;
    time[node] = low[node] = timer;
    timer++;

    for (auto &it : adj[node])
    {
        if (it == parent)
        {
            continue;
        }
        if (!vis[it])
        {
            dfs(it, node, vis, adj, time, low, bridge);
            low[node] = min(low[it], low[node]);

            if (low[it] > time[node])
            {
                bridge.push_back({it, node});
            }
        }
        else
        {
            low[node] = min(low[it], low[node]);
        }
    }
}
void Bridges(int n, vector<vector<int>> &connection)
{
    vector<vector<int>> adj(n);
    for (auto &it : connection)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> vis(n, 0);
    vector<int> time(n, INT_MAX);
    vector<int> low(n, INT_MAX);

    vector<pair<int, int>> bridge;

    dfs(0, -1, vis, adj, time, low, bridge);

    for (auto &it : bridge)
    {
        cout << it.first << " " << it.second << endl;
    }
}

int main()
{
    int n = 4;
    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};

    Bridges(n, connections);
    return 0;
}
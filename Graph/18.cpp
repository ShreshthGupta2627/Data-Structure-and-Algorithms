// Eventual safe state
/*There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.*/
#include <bits/stdc++.h>
using namespace std;

bool dfsChk(int i, vector<vector<int>> &adj, vector<int> &vis, vector<int> &path_vis)
{
    vis[i] = 1;
    path_vis[i] = 1;
    // Traverse for adjacent node and check for cycle
    for (auto &it : adj[i])
    {
        if (!vis[it])
        {
            if (dfsChk(it, adj, vis, path_vis))
            {
                return true;
            }
        }
        else if (path_vis[it])
        {
            return true;
        }
    }
    path_vis[i] = 0;
    return false;
}
vector<int> CntSafeNode(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> vis(n + 1, 0), path_vis(n + 1, 0);

    vector<int> safeNodes;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfsChk(i, adj, vis, path_vis);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (path_vis[i] == 0)
        {
            safeNodes.push_back(i);
        }
    }
    return safeNodes;
}
void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
}
int main()
{
    vector<vector<int>> adj(4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

    vector<int> ans = CntSafeNode(adj);
    cout << ans.size() << endl;
    for (auto &it : ans)
    {
        cout << it << " ";
    }
    return 0;
}
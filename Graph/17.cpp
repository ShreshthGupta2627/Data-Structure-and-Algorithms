// kahn's Algorithm
// Given a Directed Graph with V vertices and E edges, check whether it contains any cycle or not.
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
bool isDirCyclic(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> vis(n, 0), path_vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            if (dfsChk(i, adj, vis, path_vis))
            {
                return true;
            }
        }
    }
    return false;
}

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
}
int main()
{
    vector<vector<int>> adj(4);
    int n = adj.size();
    addEdge(adj, 1, 0);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);
    cout << isDirCyclic(adj) << endl;
    return 0;
}
// Topological sort
/*using dfs*/

#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st)
{
    vis[node] = 1;
    for (auto &it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, st);
        }
    }
    st.push(node);
}

void dfsCall(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> vis(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, st);
        }
    }

    vector<int> topoSort;
    while (!st.empty())
    {
        topoSort.push_back(st.top());
        st.pop();
    }
    for (auto &it : topoSort)
    {
        cout << it << " ";
    }
}
void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
}
int main()
{
    vector<vector<int>> adj(6);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);
    addEdge(adj, 4, 0);
    addEdge(adj, 4, 1);
    addEdge(adj, 5, 0);
    addEdge(adj, 5, 2);
    dfsCall(adj);
    return 0;
}
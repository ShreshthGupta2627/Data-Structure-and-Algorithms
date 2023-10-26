// Kosaraju algo -scc
#include <bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st)
{
    vis[node] = 1;

    for (auto &it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, adj, st);
        }
    }

    st.push(node);
}
void dfs3(int node, vector<int> &vis, vector<vector<int>> &adj)
{
    vis[node] = 1;

    for (auto &it : adj[node])
    {
        if (!vis[it])
        {
            dfs3(it, vis, adj);
        }
    }
}
void Kosaraju(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> vis(n, 0);

    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, st);
        }
    }
    vector<vector<int>> RevAdj(n);
    for (int i = 0; i < n; i++)
    {
        for (auto &it : adj[i])
        {
            RevAdj[it].push_back(i);
        }
    }

    vis.assign(n, 0);
    int scc = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            scc++;
            dfs3(node, vis, RevAdj);
        }
    }

    cout << scc << endl;
}
int main()
{
    int n = 5;
    int edges[5][2] = {{1, 0}, {0, 2}, {2, 1}, {0, 3}, {3, 4}};
    vector<vector<int>> adj(n);
    for (int i = 0; i < n; i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    Kosaraju(adj);
    return 0;
}
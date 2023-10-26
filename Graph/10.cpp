// Detect cycle in an undirected graph using DFS
#include <bits/stdc++.h>
using namespace std;
bool detect_my(int src, vector<int> adj[], int vis[])
{
    vis[src] = 1;
    stack<pair<int, int>> s;
    s.push({src, -1});
    while (!s.empty())
    {
        int node = s.top().first;
        int parent = s.top().second;
        s.pop();
        for (auto &adjacentNode : adj[node])
        {
            if (!vis[adjacentNode])
            {
                vis[adjacentNode] = 1;
                s.push({adjacentNode, node});
            }
            else if (parent != adjacentNode)
            {
                return true;
            }
        }
    }
    return false;
}
bool detect(int src, int parent, vector<int> adj[], int vis[])
{
    vis[src] = 1;
    for (auto &adjacentNode : adj[src])
    {
        if (!vis[adjacentNode])
        {
            if (detect(adjacentNode, src, adj, vis))
                return true;
        }
        else if (parent != adjacentNode)
        {
            return true;
        }
    }
    return false;
}
bool isCycle(int cnt_node, vector<int> adj[])
{
    int vis[cnt_node] = {0};
    for (int i = 0; i < cnt_node; i++)
    {
        if (!vis[i])
        {
            if (detect(i, -1, adj, vis))
                return true;
        }
    }
    return false;
}
int main()
{
    vector<int> adj[4] = {{1, 3}, {2}, {1, 3}, {2}};
    bool ans = isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}
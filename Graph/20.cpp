// Topological sort
/*using dfs*/

#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adj)
{
    int n = adj.size();
    queue<int> q;

    vector<int> indegree(n, 0);
    vector<int> toptSort;
    for (int i = 0; i < n; i++)
    {
        for (auto &neig : adj[i])
        {
            indegree[neig]++;
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
        toptSort.push_back(curr);
        for (auto &it : adj[curr])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    for (auto &it : toptSort)
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
    bfs(adj);
    return 0;
}
// Biparted graph using bfs

#include <bits/stdc++.h>
using namespace std;
bool isBipartite(int start, vector<vector<int>> &adj_list, vector<int> &color)
{
    int n = adj_list.size();
    queue<int> q;
    q.push(start);
    color[start] = 0;
    // can choose 1 also , just inver all color
    while (!q.empty())
    {
        int currNode = q.front();
        q.pop();
        for (auto &neig : adj_list[currNode])
        {
            // Adj is not yet colored
            if (color[neig] == -1)
            {
                color[neig] = !color[currNode];
                q.push(neig);
            }
            // is adj having same color i.e some else path alredy coloured it before
            else if (color[neig] == color[currNode])
            {
                return false;
            }
        }
    }
    return true;
}
void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{
    vector<vector<int>> adj(4);
    int n = adj.size();
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 1, 3);
    //-1 is to represent no color
    vector<int> color(n, -1);
    bool flag = 1;
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!isBipartite(i, adj, color))
            {
                flag = 0;
            }
        }
    }
    if (flag)
    {
        cout << "is Bipartite" << endl;
    }
    else
    {
        cout << "is not Bipartite" << endl;
    }
    // TC : same as bfs
    return 0;
}

// Bipartite Graph
/*Given an adjacency list of a graph adj of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
If we are able to colour a graph with two colours such that no adjacent nodes have the same colour, it is called a bipartite graph.*/

#include <bits/stdc++.h>
using namespace std;

bool dfs(int ind, int col, vector<vector<int>> &adj_list, vector<int> &color)
{
    color[ind] = col;
    for (auto &it : adj_list[ind])
    {
        if (color[it] == -1)
        {
            if (!dfs(it, !col, adj_list, color))
                return false;
        }
        else if (col == color[it])
        {
            return false;
        }
    }
    return true;
}
bool isBipartite(int start, vector<vector<int>> &adj_list)
{
    //-1 is to represent no color
    vector<int> color(adj_list.size(), -1);
    for (int i = 0; i < adj_list.size(); i++)
    {
        if (color[i] == -1)
        {
            if (!dfs(i, 0, adj_list, color))
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
    cout << isBipartite(1, adj) << endl;
    return 0;
}
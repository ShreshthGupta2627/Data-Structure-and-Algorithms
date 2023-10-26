// Kruskrul's Algorithm
#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int Find_U_Parent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = Find_U_Parent(parent[node]);
    }
    void UnionByRank(int u, int v)
    {
        int ulp_u = Find_U_Parent(u);
        int ulp_v = Find_U_Parent(v);
        if (ulp_v == ulp_u)
        {
            return;
        }
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_u] > rank[ulp_v])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void UnionBySize(int u, int v)
    {
        int ulp_u = Find_U_Parent(u);
        int ulp_v = Find_U_Parent(v);
        if (ulp_v == ulp_u)
        {
            return;
        }
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

void Wt_u_v_Form(vector<pair<int, pair<int, int>>> &edges, vector<vector<pair<int, int>>> &adj)
{
    for (int i = 0; i < adj.size(); i++)
    {
        for (auto &it : adj[i])
        {
            int u = i;
            int v = it.first;
            int wt = it.second;
            edges.push_back({wt, {u, v}});
        }
    }

    sort(edges.begin(), edges.end());
}
void Kruskrulls(int v, vector<pair<int, pair<int, int>>> &edges)
{
    DisjointSet ds(v);

    int MstWeight = 0;
    vector<pair<int, int>> mst;
    for (auto &it : edges)
    {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if (ds.Find_U_Parent(u) != ds.Find_U_Parent(v))
        {
            MstWeight += wt;
            ds.UnionByRank(u, v);
            mst.push_back({u, v});
        }
    }

    cout << MstWeight << endl;
}
void addEdge(vector<vector<pair<int, int>>> &adj, int u, int v, int wt)
{
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
}
int main()
{
    vector<vector<pair<int, int>>> adj(7);
    addEdge(adj, 1, 4, 1);
    addEdge(adj, 1, 2, 2);
    addEdge(adj, 2, 3, 3);
    addEdge(adj, 2, 4, 3);
    addEdge(adj, 1, 5, 4);
    addEdge(adj, 3, 4, 5);
    addEdge(adj, 2, 6, 7);
    addEdge(adj, 3, 6, 8);
    addEdge(adj, 4, 5, 9);

    vector<pair<int, pair<int, int>>> edges;
    Wt_u_v_Form(edges, adj);
    // O(N+E) + O(E log E)[sort]

    Kruskrulls(7, edges);
    // O(E * 4 * alpha)
    return 0;
}
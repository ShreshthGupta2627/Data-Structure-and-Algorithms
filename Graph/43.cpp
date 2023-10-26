// Problem Statement: Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces. -> Using Disjoint Set
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

int main()
{
    vector<vector<int>> adj = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
    int n = adj.size();
    // If we cnt where node = up[node] is our ans
    DisjointSet ds(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j])
            {
                ds.UnionByRank(i, j);
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (ds.Find_U_Parent(i) == i)
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
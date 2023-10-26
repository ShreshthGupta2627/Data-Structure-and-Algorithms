// Number of Operations to Make Network Connected – DSU
/* You are given a graph with n vertices and m edges. You can remove one edge from anywhere and add that edge between any two vertices in one operation. Find the minimum number of operations that will be required to make the graph connected. If it is not possible to make the graph connected, return -1.*/

#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
private:
public:
    vector<int> rank, parent, size;
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

int cnt(int n, vector<pair<int, int>> &edges)
{
    DisjointSet ds(n);
    int CntExtras = 0;
    for (auto &it : edges)
    {
        int u = it.first;
        int v = it.second;

        if (ds.Find_U_Parent(u) == ds.Find_U_Parent(v))
        {
            CntExtras++;
        }
        else
        {
            ds.UnionByRank(u, v);
        }
    }

    int CntC = 0;
    for (int i = 0; i < n; i++)
    {
        if (ds.parent[i] == i)
        {
            CntC++;
        }
    }
    int ans = CntC - 1;

    if (CntExtras >= ans)
    {
        return ans;
    }
    else
    {
        return -1;
    }
}
int main()
{
    vector<pair<int, int>> p = {{0, 1}, {0, 3}, {0, 2}, {1, 2}, {2, 3}, {4, 5}, {5, 6}, {7, 8}};
    cout << cnt(8, p) << endl;
    return 0;
}
// Most Stones Removed with Same Row or Column
/*There are n stones at some integer coordinate points on a 2D plane. Each coordinate point may have at most one stone.
You need to remove some stones.
A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.
Given an array of stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the maximum possible number of stones that you can remove.*/

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
void cnt(vector<pair<int, int>> &stones, int n)
{
    int maxRow = 0, maxCol = 0;
    for (auto &it : stones)
    {
        maxRow = max(maxRow, it.first);
        maxCol = max(maxCol, it.second);
    }

    DisjointSet ds(maxRow + maxCol + 1);
    unordered_map<int, int> mp;

    for (auto &it : stones)
    {
        int nodeRow = it.first;
        int nodeCol = it.second + maxRow + 1;
        //+1+maxRow to shift in ds
        mp[nodeRow] = 1;
        mp[nodeCol] = 1;
        ds.UnionByRank(nodeRow, nodeCol);
    }

    int cnt = 0;
    for (auto &it : mp)
    {
        if (ds.Find_U_Parent(it.first) == it.first)
        {
            cnt++;
        }
    }
    cout << n - cnt << endl;
}
int main()
{
    int n = 6;
    vector<pair<int, int>> stones = {{0, 0}, {0, 2}, {1, 3}, {3, 1}, {3, 2}, {4, 3}};
    cnt(stones, n);
    return 0;
}
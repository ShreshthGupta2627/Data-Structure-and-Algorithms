// Disjoint Set
#include <bits/stdc++.h>
using namespace std;
class DisjointSet
{
private:
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        // Assuming the case to be handeled can be 1 based indexing
        // initializing nrank to 0
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
        // Storing in parent node will make path compression for future queries
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
    DisjointSet ds(7);
    ds.UnionByRank(1, 2);
    ds.UnionByRank(2, 3);
    ds.UnionByRank(4, 5);
    ds.UnionByRank(6, 7);
    ds.UnionByRank(5, 6);
    cout << "Does 3,7 belong to same component of graph ? ";
    if (ds.Find_U_Parent(3) == ds.Find_U_Parent(7))
    {
        cout << " : YES" << endl;
    }
    else
    {
        cout << " : NO" << endl;
    }

    ds.UnionByRank(3, 7);

    cout << "Does 3,7 now belong to same component of graph ? ";
    if (ds.Find_U_Parent(3) == ds.Find_U_Parent(7))
    {
        cout << " : YES" << endl;
    }
    else
    {
        cout << " : NO" << endl;
    }
    return 0;
}
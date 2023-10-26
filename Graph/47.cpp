// Making a Large Island
/* You are given an n x n binary grid. A grid is said to be binary if every value in the grid is either 1 or 0. You can change at most one cell in the grid from 0 to 1. You need to find the largest group of connected  1’s. Two cells are said to be connected if both are adjacent to each other and both have the same value.*/

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

void cnt(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<pair<int, int>> d = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    DisjointSet ds(n * m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + d[k].first;
                    int ny = j + d[k].second;

                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1)
                    {
                        int node_id = i * m + j;
                        int adjNode_id = nx * m + ny;
                        ds.UnionBySize(node_id, adjNode_id);
                    }
                }
            }
        }
    }

    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 0)
            {
                set<int> up;
                for (int k = 0; k < 4; k++)
                {
                    int nx = i + d[k].first;
                    int ny = j + d[k].second;

                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 1)
                    {
                        int node_id = nx * m + ny;
                        up.insert(ds.Find_U_Parent(node_id));
                    }
                }

                int temp = 1;
                for (auto &it : up)
                {
                    temp += ds.size[it];
                }
                up.clear();
                ans = max(ans, temp);
            }
        }
    }

    for (int cellNo = 0; cellNo < n * m; cellNo++)
    {
        ans = max(ans, ds.size[ds.Find_U_Parent(cellNo)]);
    }
    cout << ans << endl;
}
int main()
{
    vector<vector<int>> grid = {{1, 1, 0, 1, 1, 0}, {1, 1, 0, 1, 1, 0}, {1, 1, 0, 1, 1, 0}, {0, 0, 1, 0, 0, 0}, {0, 0, 1, 1, 1, 0}, {0, 0, 1, 1, 1, 0}};
    cnt(grid);
    return 0;
}
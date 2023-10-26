// Number of islands - 2
/*You are given an n, m which means the row and column of the 2D matrix, and an array of size k denoting the number of operations. Matrix elements are 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator(s) and each operator has two integers A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many islands are there in the matrix after each operation. You need to return an array of size k.

Note: An island means a group of 1s such that they share a common side*/

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

void NumOfIsland(vector<vector<int>> &grid, vector<pair<int, int>> &corr)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));

    int maxx_id = n * m;
    DisjointSet ds(maxx_id);
    vector<pair<int, int>> d = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

    int cnt = 0;
    vector<int> ans;

    for (auto &edge : corr)
    {
        int x = edge.first;
        int y = edge.second;

        if (vis[x][y] == 1)
        {
            ans.push_back(cnt);
        }
        else
        {
            vis[x][y] = 1;
            cnt++;
            for (int i = 0; i < 4; i++)
            {
                int dx = d[i].first;
                int dy = d[i].second;

                int nx = x + dx;
                int ny = y + dy;

                if (nx >= 0 && nx < n && ny >= 0 && ny < m)
                {
                    if (vis[nx][ny] == 1)
                    {
                        int node_id = x * m + y;
                        int Adj_node_id = nx * m + ny;

                        if (ds.Find_U_Parent(node_id) != ds.Find_U_Parent(Adj_node_id))
                        {
                            cnt--;
                            ds.UnionByRank(node_id, Adj_node_id);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << " " << ans[i];
    }
}
int main()
{
    int n = 4, m = 5;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<pair<int, int>> corr = {{0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1}, {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2}, {1, 2}, {0, 2}};
    NumOfIsland(grid, corr);
    return 0;
}
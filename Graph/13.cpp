// Number of Enclaves
/* You are given an N x M binary matrix grid, where 0 represents a sea cell and 1 represents a land cell. A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid. Find the number of land cells in the grid for which we cannot walk off the boundary of the grid in any number of moves.*/

#include <bits/stdc++.h>
using namespace std;
int bfs(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n + 1, vector<int>(m, 0));
    queue<pair<int, int>> q;
    // We will push all 1 on boundry
    for (int j = 0; j < m; j++)
    {
        if (grid[0][j] == 1)
        {
            q.push({0, j});
            vis[0][j] = 1;
        }
        if (grid[n - 1][j] == 1)
        {
            q.push({n - 1, j});
            vis[n - 1][j] = 1;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == 1)
        {
            q.push({i, 0});
            vis[i][0] = 1;
        }
        if (grid[i][m - 1] == 1)
        {
            q.push({i, m - 1});
            vis[i][m - 1] = 1;
        }
    }
    vector<int> delrow = {-1, 0, +1, 0};
    vector<int> delcol = {0, +1, 0, -1};
    while (!q.empty())
    {
        pair<int, int> currPos = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nRow = currPos.first + delrow[i];
            int nCol = currPos.second + delcol[i];
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && grid[nRow][nCol] == 1)
            {
                vis[nRow][nCol] = 1;
                q.push({nRow, nCol});
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && !vis[i][j])
                ans++;
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> grid{{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    cout << bfs(grid) << endl;
    return 0;
}
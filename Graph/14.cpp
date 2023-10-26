// Number of Distinct Islands
/* Given a boolean 2D matrix grid of size N x M. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).*/

#include <bits/stdc++.h>
using namespace std;
void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<pair<int, int>> &pairs, int baseRow, int baseCol)
{
    int n = grid.size();
    int m = grid[0].size();
    vis[row][col] = 1;

    // Converting the (row,col) relative to the base
    pairs.push_back({row - baseRow, col - baseCol});

    // Thi will automatically maintain a order to store sequence before storing in set
    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, -1, 0, 1};
    for (int i = 0; i < 4; i++)
    {
        int nRow = row + delrow[i];
        int nCol = col + delcol[i];
        if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && grid[nRow][nCol] == 1)
        {
            dfs(nRow, nCol, vis, grid, pairs, baseRow, baseCol);
        }
    }
}
int cntDistinctIsland(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == 1)
            {
                vector<pair<int, int>> p;
                dfs(i, j, vis, grid, p, i, j);
                st.insert(p);
            }
        }
    }
    return st.size();
    // TC : O(n*m*log(n*m)) + O(n*m*4)
    //  O(loops*set inset)  + O(overall dfs)
}
int main()
{
    vector<vector<int>> grid{{1, 1, 0, 1, 1}, {1, 0, 0, 0, 0}, {0, 0, 0, 0, 1}, {1, 1, 0, 1, 1}};
    cout << cntDistinctIsland(grid) << endl;
    return 0;
}
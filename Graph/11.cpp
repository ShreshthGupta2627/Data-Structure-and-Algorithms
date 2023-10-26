/*Distance of Nearest Cell having 1

Given a binary grid of N*M. Find the distance of the nearest 1 in the grid for each cell.
The distance is calculated as |i1  – i2| + |j1 – j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 are the row number and column number of the nearest cell having value 1.*/
#include <bits/stdc++.h>
using namespace std;
bool inLimit(int row, int col, int n, int m)
{
    if (row >= 0 && row < n && col >= 0 && col < m)
        return true;
    return false;
}
vector<vector<int>> nearestone(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
        }
    }
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};
    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        dist[row][col] = steps;
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (inLimit(nrow, ncol, n, m) && !vis[nrow][ncol])
            {
                vis[nrow][ncol] = 1;
                q.push({{nrow, ncol}, steps + 1});
            }
        }
    }
    // TC : O(4*N*M)
    return dist;
}
int main()
{
    vector<vector<int>> grid = {{0, 0, 0}, {0, 1, 0}, {1, 0, 1}};
    vector<vector<int>> dist = nearestone(grid);
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Distance of nearest 1 array : " << endl
         << endl;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
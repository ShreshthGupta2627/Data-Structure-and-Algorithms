// Surrounded regions
/* Given a matrix mat of size N x M where every element is either ‘O’ or ‘X’. Replace all ‘O’ with ‘X’ that is surrounded by ‘X’. An ‘O’ (or a set of ‘O’) is considered to be surrounded by ‘X’ if there are ‘X’ at locations just below, just above just left, and just right of it. */
#include <bits/stdc++.h>
using namespace std;
void dfs(int row, int col, vector<vector<bool>> &vis, vector<vector<char>> &mat, vector<int> &delrow, vector<int> &delcol)
{
    int n = mat.size();
    int m = mat[0].size();
    vis[row][col] = 1;
    // Chk for top , right , bottom , left
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O')
        {
            dfs(nrow, ncol, vis, mat, delrow, delcol);
        }
    }
}
vector<vector<char>> fill(int n, int m, vector<vector<char>> &mat)
{
    // Chk for top , right , bottom , left
    vector<int> delrow = {-1, 0, +1, 0};
    vector<int> delcol = {0, +1, 0, -1};

    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    // Traverse all boundry to find connected (direct or indirect O's) with boundry
    // Traversing first row ad last row
    for (int j = 0; j < m; j++)
    {
        // first row
        if (!vis[0][j] && mat[0][j] == 'O')
        {
            dfs(0, j, vis, mat, delrow, delcol);
        }

        // last row
        if (!vis[n - 1][j] && mat[n - 1][j] == 'O')
        {
            dfs(n - 1, j, vis, mat, delrow, delcol);
        }
    }

    // Similar for first and last coloumn
    for (int i = 0; i < n; i++)
    {
        // first col
        if (!vis[i][0] && mat[i][0] == 'O')
        {
            dfs(i, 0, vis, mat, delrow, delcol);
        }

        // last col
        if (!vis[i][m - 1] && mat[i][m - 1] == 'O')
        {
            dfs(i, m - 1, vis, mat, delrow, delcol);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && mat[i][j] == 'O')
            {
                mat[i][j] = 'X';
            }
        }
    }
    return mat;
}
int main()
{

    // Tc : 4*O(N*M) + O(N)
    // dfs + loop

    vector<vector<char>> mat{
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'O'}};

    int n = mat.size(), m = mat[0].size();
    vector<vector<char>> ans = fill(n, m, mat);
    for (auto &it : ans)
    {
        for (auto &it1 : it)
        {
            cout << it1 << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
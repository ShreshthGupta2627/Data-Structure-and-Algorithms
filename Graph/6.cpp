// No of connected component
/* Given an undirected graph with V vertices.We say two vertices u and v belong to a single province if there is a path from u to v or v to u.Your task is to find the number of provinces.
 Note : A province is a group of directly or indirectly connected cities and no other cities outside of the group. */
// Input : { {1,0,1} , {0,1,0} , {1,0,1}}
// Output : 2

#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Traverse in neighbour and mark them if its a land
            for (int delrow = -1; delrow <= 1; delrow++)
            {
                for (int delcol = -1; delcol <= 1; delcol++)
                {
                    int nrow = row + delrow;
                    int ncol = col + delcol;

                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol])
                    {
                        vis[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                    }
                }
            }
        }
    }

public:
    int numIsland(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for (int row = 0; row < n; row++)
        {
            for (int column = 0; column < m; column++)
            {
                if (!vis[row][column] && grid[row][column] == '1')
                {
                    cnt++;
                    bfs(row, column, vis, grid);
                }
            }
        }
        return cnt;
    }
};
int main()
{
    vector<vector<char>> v = {{'0', '1', '1', '1', '0', '0', '0'}, {'0', '0', '1', '1', '0', '1', '0'}};
    Solution s;
    cout << s.numIsland(v) << endl;
    return 0;
}
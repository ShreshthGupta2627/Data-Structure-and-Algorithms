// Rotten oranges
/*Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
0 : Empty cell
1 : Cells have fresh oranges
2 : Cells have rotten oranges
We have to determine what is the minimum time required to rot all oranges. A rotten orange at index [i,j] can rot other fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time.

del row=-1 , 0 , +1 , 0
del col=0 , +1 , +0 , -1

Input: grid = {{0,1,2},{0,1,2},{2,1,1}}
Output: 1
Explanation: The grid is-
0 1 2
0 1 2
2 1 1
Oranges at positions (0,2), (1,2), (2,0) will rot oranges at (0,1), (1,1), (2,2) and (2,1) in unit time. */

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int rottenOranges(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        //((row,col),time)
        queue<pair<pair<int, int>, int>> q;
        // Space : n*m
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // Space : n*m
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
            }
        }
        int Maxtime = 0;
        // Space : 1
        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            // Space : 3
            Maxtime = max(Maxtime, t);
            q.pop();
            // del row=-1 , 0 , +1 , 0
            // del col=0 , +1 , +0 , -1
            int drow[] = {-1, 0, +1, 0};
            int dcol[] = {0, +1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                // Space : 2
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1)
                {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 2;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] != 2 && grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        return Maxtime;
        // Total space : O( 2*n*m + 6 ) ==> O(n*m)
        // Time Complexcity : O( n * m )
    }
};
int main()
{
    vector<vector<int>> grid1 = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    // ans : 4
    vector<vector<int>> grid2 = {{1, 2, 1}, {1, 1, 0}, {0, 0, 1}};
    // ans : -1
    Solution s;
    cout << s.rottenOranges(grid1) << endl;
    cout << s.rottenOranges(grid2) << endl;
    return 0;
}
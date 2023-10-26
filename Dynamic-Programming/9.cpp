/* given a n*m maze with obstacles count and return the number of unique paths to reach the right bottom cell from the top left cell a cell in the given maze has a value 1 if it is a blockage or dead end else 0 from a given cell we are allowed to move to cells (i+1,j) and (i,j+1) only since the answer can be large print it modulo 10^9+7

Input:
0 0 0
0 -1 0
0 0 0

Output:
( 1 , 1 ) -> ( 1 , 2 ) -> ( 1 , 3 ) -> ( 2 , 3 ) -> ( 3 , 3 )
( 1 , 1 ) -> ( 2 , 1 ) -> ( 3 , 1 ) -> ( 3 , 2 ) -> ( 3 , 3 )

Ans: 2
*/
#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j, vector<vector<int>> &v)
{
    if (i < 0 || j < 0)
        return 0;
    if (v[i][j] == -1)
        return 0;
    if (i == 0 && j == 0)
        return 1;
    int up = solve(i - 1, j, v);
    int left = solve(i, j - 1, v);
    return left + up;
}
int solve_with_memoization(int i, int j, vector<vector<int>> &v, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;
    if (v[i][j] == -1)
        return 0;
    if (i == 0 && j == 0)
        return dp[0][0] = 1;
    int up = solve_with_memoization(i - 1, j, v, dp);
    int left = solve_with_memoization(i, j - 1, v, dp);
    return dp[i][j] = left + up;
}
int solve_with_tabulation(vector<vector<int>> &v)
{
    vector<vector<int>> dp(v.size(), vector<int>(v[0].size(), -1));
    dp[0][0] = 1;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            if (v[i][j] == -1)
            {
                dp[i][j] = 0;
                continue;
            }
            else if (i == 0 && j == 0)
            {
                continue;
            }
            int up = i > 0 ? dp[i - 1][j] : 0;
            int left = j > 0 ? dp[i][j - 1] : 0;
            dp[i][j] = up + left;
        }
    }
    return dp[v.size() - 1][v[0].size() - 1];
}
int solve_with_spaceOptimization(int n, int m, vector<vector<int>> &maze)
{
    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> temp(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (maze[i][j] == -1)
            {
                temp[j] = 0;
                continue;
            }
            if (i == 0 && j == 0)
            {
                temp[j] = 1;
                continue;
            }
            int up = i > 0 ? prev[j] : 0;
            int left = j > 0 ? temp[j - 1] : 0;
            temp[j] = up + left;
        }
        prev = temp;
    }
    return prev[n - 1];
}
int main()
{
    int n = 5, m = 5;
    vector<vector<int>> v = {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, -1, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << solve(n - 1, m - 1, v) << endl;
    cout << solve_with_memoization(n - 1, m - 1, v, dp) << endl;
    cout << solve_with_tabulation(v) << endl;
    cout << solve_with_spaceOptimization(n, m, v) << endl;
    return 0;
}
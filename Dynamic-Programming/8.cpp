/*There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The test cases are generated so that the answer will be less than or equal to 2 * e9.

Input:
m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
*/
#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j)
{
    if (i == 0 && j == 0)
        return 1;
    // Out of bound
    if (i < 0 || j < 0)
        return 0;
    int up = solve(i - 1, j);
    int left = solve(i, j - 1);
    return up + left;
}
int solve_with_memoization(vector<vector<int>> &dp, int i, int j)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = solve(i - 1, j);
    int left = solve(i, j - 1);
    return dp[i][j] = (up + left);
}
int solve_with_tabulation(int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                continue;
            else
            {
                int up = 0, left = 0;
                if (i > 0)
                    up = dp[i - 1][j];
                if (j > 0)
                    left = dp[i][j - 1];
                dp[i][j] = left + up;
            }
        }
    }
    return dp[n - 1][m - 1];
}
int solve_with_spaceOptimization(int n, int m)
{
    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                curr[j] = 1;
            else
            {
                int up = 0, left = 0;
                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = curr[j - 1];
                curr[j] = up + left;
            }
        }
        prev = curr;
    }
    return prev[m - 1];
}
int main()
{
    int n = 3, m = 3;
    cout << solve(n - 1, m - 1) << endl;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << solve_with_memoization(dp, n - 1, m - 1) << endl;
    cout << solve_with_tabulation(n, m) << endl;
    cout << solve_with_spaceOptimization(n, m) << endl;
    return 0;
}
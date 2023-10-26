/*You have been given an N *M matrix filled with integer numbers, find the maximum sum that can be obtained from a path starting from any cell in the first row to any cell in the last row.

From a cell in a row, you can move to another cell directly below that row, or diagonally below left or right. So from a particular cell (row, col), we can move in three directions i.e.

how we can move:

Down: (row+1,col)
Down left diagonal: (row+1,col-1)
Down right diagonal: (row+1, col+1)
*/

#include <bits/stdc++.h>
using namespace std;
int sub_solve(int i, int j, vector<vector<int>> &v)
{
    int n = v.size();
    int m = v[0].size();
    if (j < 0 || j >= m)
        return -1e9;
    if (i == 0)
        return v[i][j];
    int straight = v[i][j] + sub_solve(i - 1, j, v);      // up
    int dig_left = v[i][j] + sub_solve(i - 1, j - 1, v);  // left up
    int dig_right = v[i][j] + sub_solve(i - 1, j + 1, v); // right up
    return max(straight, max(dig_left, dig_right));
}
int solve(vector<vector<int>> &v)
{
    int n = v.size();
    int m = v[0].size();
    int ans = INT_MIN;
    for (int j = 0; j < m; j++)
    {
        ans = max(ans, sub_solve(n - 1, j, v));
    }
    return ans;
}

// Solution by recursion ended

int sub_solve_for_memoization(int i, int j, vector<vector<int>> &v, vector<vector<int>> &dp)
{
    int n = v.size();
    int m = v[0].size();
    if (j < 0 || j >= m)
        return -1e9;
    if (i == 0)
        return dp[i][j] = v[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int straight = v[i][j] + sub_solve_for_memoization(i - 1, j, v, dp);      // up
    int dig_left = v[i][j] + sub_solve_for_memoization(i - 1, j - 1, v, dp);  // left up
    int dig_right = v[i][j] + sub_solve_for_memoization(i - 1, j + 1, v, dp); // right up
    return dp[i][j] = max(straight, max(dig_left, dig_right));
}
int solve_memoization(vector<vector<int>> &v)
{
    int n = v.size();
    int m = v[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ans = INT_MIN;
    for (int j = 0; j < m; j++)
    {
        ans = max(ans, sub_solve_for_memoization(n - 1, j, v, dp));
    }
    return ans;
}

// Solution by memoization ended

int solve_tabulation(vector<vector<int>> &v)
{
    int n = v.size();
    int m = v[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = v[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int straight = v[i][j] + dp[i - 1][j];
            int dig_left = j > 0 ? v[i][j] + dp[i - 1][j - 1] : -1e9;
            int dig_right = j < m - 1 ? v[i][j] + dp[i - 1][j + 1] : -1e9;
            dp[i][j] = max(straight, max(dig_left, dig_right));
        }
    }
    int maxi = dp[n - 1][0];
    for (int j = 1; j < m; j++)
    {
        maxi = max(maxi, dp[n - 1][j]);
    }
    return maxi;
}

// Solution by tabulation ended

int solve_spaceOptimised(vector<vector<int>> &v)
{
    int n = v.size();
    int m = v[0].size();
    vector<int> prev(m, 0), curr(m, 0);
    for (int j = 0; j < m; j++)
    {
        prev[j] = v[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int straight = v[i][j] + prev[j];
            int dig_left = j > 0 ? v[i][j] + prev[j - 1] : -1e9;
            int dig_right = j < m - 1 ? v[i][j] + prev[j + 1] : -1e9;
            curr[j] = max(straight, max(dig_left, dig_right));
        }
        prev = curr;
    }
    int maxi = INT_MIN;
    for (int j = 1; j < m; j++)
    {
        maxi = max(maxi, prev[j]);
    }
    return maxi;
}
int main()
{
    vector<vector<int>> v = {{1, 2, 10, 4}, {100, 3, 2, 1}, {1, 1, 20, 2}, {1, 2, 2, 1}};
    cout << solve(v) << endl;
    cout << solve_memoization(v) << endl;
    cout << solve_tabulation(v) << endl;
    cout << solve_spaceOptimised(v) << endl;
    return 0;
}
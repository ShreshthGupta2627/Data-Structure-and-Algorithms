/*We are given an N*M matrix of integers. We need to find a path from the top-left corner to the bottom-right corner of the matrix, such that there is a minimum cost past that we select.
At every cell, we can move in only two directions: right and bottom. The cost of a path is given as the sum of values of cells of the given matrix.
Input:
v={ {5,9,6} , {11,5,2} }
Output:
5+9+5+2 = 21
*/
#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j, vector<vector<int>> &v)
{
    if (i == 0 && j == 0)
        return v[i][j];
    if (i < 0 || j < 0)
        return pow(10, 9);
    int up = v[i][j] + solve(i - 1, j, v);
    int left = v[i][j] + solve(i, j - 1, v);
    return min(left, up);
}
int solve_with_memoization(int i, int j, vector<vector<int>> &v, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return dp[i][j] = v[i][j];
    if (i < 0 || j < 0)
        return pow(10, 9);
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = v[i][j] + solve(i - 1, j, v);
    int left = v[i][j] + solve(i, j - 1, v);
    return dp[i][j] = min(left, up);
}
int solve_with_tabulation(int n, int m, vector<vector<int>> &v)
{
    vector<vector<int>> dp(n, vector<int>(m, -1));
    dp[0][0] = v[0][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
                continue;
            int up = i > 0 ? (v[i][j] + dp[i - 1][j]) : pow(10, 9);
            int left = j > 0 ? (v[i][j] + dp[i][j - 1]) : pow(10, 9);
            dp[i][j] = min(up, left);
        }
    }
    return dp[n - 1][m - 1];
}
int solve_with_space_optimization(vector<vector<int>> &v)
{
    int n = v.size();
    int m = v[0].size();
    vector<int> prev(m, 0);
    for (int i = 0; i < n; i++)
    {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                curr[j] = v[i][j];
            }
            else
            {
                int up = i > 0 ? (v[i][j] + prev[j]) : pow(10, 9);
                int left = j > 0 ? (v[i][j] + curr[j - 1]) : pow(10, 9);
                curr[j] = min(left, up);
            }
        }
        prev = curr;
    }
    return prev[m - 1];
}
int main()
{
    vector<vector<int>> v = {{5, 9, 6}, {11, 5, 2}};
    int n = v.size(), m = v[0].size();
    cout << solve(n - 1, m - 1, v) << endl;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << solve_with_memoization(n - 1, m - 1, v, dp) << endl;
    cout << solve_with_tabulation(n, m, v) << endl;
    cout << solve_with_space_optimization(v) << endl;
    return 0;
}
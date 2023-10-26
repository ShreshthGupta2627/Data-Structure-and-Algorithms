// 3d dp
/*Ninja has a 'GRID' of size 'R' X 'C'. Each cell of the grid contains some chocolates. Ninja has two friends Alice and Bob, and he wants to collect as many chocolates as possible with the help of his friends.

Initially, Alice is in the top-left position i.e. (0, 0), and Bob is in the top-right place i.e. (0, ‘C’ - 1) in the grid. Each of them can move from their current cell to the cells just below them. When anyone passes from any cell, he will pick all chocolates in it, and then the number of chocolates in that cell will become zero. If both stay in the same cell, only one of them will pick the chocolates in it.

If Alice or Bob is at (i, j) then they can move to (i + 1, j), (i + 1, j - 1) or (i + 1, j + 1). They will always stay inside the ‘GRID’.

Your task is to find the maximum number of chocolates Ninja can collect with the help of his friends by following the above rules.

Input: ‘R’ = 3, ‘C’ = 4
GRID’ = [[2, 3, 1, 2], [3, 4, 2, 2], [5, 6, 3, 5]]
Output: 21
*/
#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j1, int j2, vector<vector<int>> &a)
{
    if (j1 < 0 || j1 >= a[0].size() || j2 < 0 || j2 >= a[0].size())
    {
        return -1e9;
    }
    if (i == a.size() - 1)
    {
        if (j1 == j2)
        {
            return a[i][j1];
        }
        else
        {
            return a[i][j1] + a[i][j2];
        }
    }
    int dj[] = {-1, 0, 1}, maxi = INT_MIN;
    for (auto &it1 : dj)
    {
        for (auto &it2 : dj)
        {
            if (j1 == j2)
            {
                maxi = max(maxi, a[i][j1] + solve(i + 1, j1 + it1, j2 + it2, a));
            }
            else
            {
                maxi = max(maxi, a[i][j1] + a[i][j2] + solve(i + 1, j1 + it1, j2 + it2, a));
            }
        }
    }
    return maxi;
}

int solve_with_memoization(int i, int j1, int j2, vector<vector<int>> &a, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j1 >= a[0].size() || j2 < 0 || j2 >= a[0].size())
    {
        return -1e9;
    }
    if (i == a.size() - 1)
    {
        if (j1 == j2)
        {
            return dp[i][j1][j2] = a[i][j1];
        }
        else
        {
            return dp[i][j1][j2] = a[i][j1] + a[i][j2];
        }
    }
    if (dp[i][j1][j2] != -1)
    {
        return dp[i][j1][j2];
    }
    int dj[] = {-1, 0, 1}, maxi = INT_MIN;
    for (auto &it1 : dj)
    {
        for (auto &it2 : dj)
        {
            if (j1 == j2)
            {
                maxi = max(maxi, a[i][j1] + solve(i + 1, j1 + it1, j2 + it2, a));
            }
            else
            {
                maxi = max(maxi, a[i][j1] + a[i][j2] + solve(i + 1, j1 + it1, j2 + it2, a));
            }
        }
    }
    return dp[i][j1][j2] = maxi;
}

int solve_with_tabulation(int n, int m, vector<vector<int>> &a)
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    // Defining base case
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                dp[n - 1][j1][j2] = a[n - 1][j1];
            else
                dp[n - 1][j1][j2] = a[n - 1][j1] + a[n - 1][j2];
        }
    }

    // applying operations => 0->n in memo. :. n->0 in tabu.
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = -1e9;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int val = 0;
                        if (j1 == j2)
                            val = a[i][j1];
                        else
                            val = a[i][j1] + a[i][j2];
                        if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                            val += dp[i + 1][j1 + dj1][j2 + dj2];
                        else
                            val += -1e9;

                        maxi = max(maxi, val);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][m - 1];
}

int solve_space_optimised(int n, int m, vector<vector<int>> &a)
{
    vector<vector<int>> front(m, vector<int>(m, 0));
    vector<vector<int>> curr(m, vector<int>(m, 0));
    for (int j1 = 0; j1 < m; j1++)
    {
        for (int j2 = 0; j2 < m; j2++)
        {
            if (j1 == j2)
                front[j1][j2] = a[n - 1][j1];
            else
                front[j1][j2] = a[n - 1][j1] + a[n - 1][j2];
        }
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                int maxi = -1e9;
                for (int dj1 = -1; dj1 <= 1; dj1++)
                {
                    for (int dj2 = -1; dj2 <= 1; dj2++)
                    {
                        int val = 0;
                        if (j1 == j2)
                            val = a[i][j1];
                        else
                            val = a[i][j1] + a[i][j2];
                        if (j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m)
                            val += front[j1 + dj1][j2 + dj2];
                        else
                            val += -1e9;

                        maxi = max(maxi, val);
                    }
                }
                curr[j1][j2] = maxi;
            }
        }
        front = curr;
    }
    return front[0][m - 1];
}
int main()
{
    vector<vector<int>> grid = {{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}};
    int n = grid.size(), m = grid[0].size();
    cout << solve(0, 0, m - 1, grid) << endl;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    cout << solve_with_memoization(0, 0, m - 1, grid, dp) << endl;
    cout << solve_with_tabulation(n, m, grid) << endl;
    cout << solve_space_optimised(n, m, grid) << endl;
    return 0;
}
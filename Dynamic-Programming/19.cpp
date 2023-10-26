/* A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and the ith item weighs wi and is of value vi. Considering the constraints of the maximum weight that a knapsack can carry, you have to find and return the maximum value that a thief can generate by stealing items. */
#include <bits/stdc++.h>
using namespace std;
int solve(int ind, int w, vector<int> &wt, vector<int> &val)
{
    if (ind == 0)
    {
        if (w >= wt[ind])
            return val[ind];
        return 0;
    }
    int notpick = solve(ind - 1, w, wt, val);
    int pick = INT_MIN;
    if (w >= wt[ind])
    {
        pick = val[ind] + solve(ind - 1, w - wt[ind], wt, val);
    }
    return max(pick, notpick);
}

int solve_mem(int ind, int w, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (w >= wt[ind])
            return val[ind];
        return 0;
    }
    if (dp[ind][w] != -1)
        return dp[ind][w];
    int notpick = solve(ind - 1, w, wt, val);
    int pick = INT_MIN;
    if (w >= wt[ind])
    {
        pick = val[ind] + solve(ind - 1, w - wt[ind], wt, val);
    }
    return dp[ind][w] = max(pick, notpick);
}

int solve_tab(int n, int w, vector<int> &wt, vector<int> &val)
{
    vector<vector<int>> dp(n, vector<int>(w + 1, 0));
    for (int i = wt[0]; i <= w; i++)
    {
        dp[0][i] = val[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            int notpick = dp[i - 1][j];
            int pick = INT_MIN;
            if (j >= wt[i])
            {
                pick = val[i] + dp[i - 1][j - wt[i]];
            }
            dp[i][j] = max(pick, notpick);
        }
    }
    return dp[n - 1][w];
}
int solve_sopt1(int n, int w, vector<int> &wt, vector<int> &val)
{
    vector<int> curr(w + 1, 0), prev(w + 1, 0);
    for (int i = wt[0]; i <= w; i++)
    {
        prev[i] = val[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            int notpick = prev[j];
            int pick = INT_MIN;
            if (j >= wt[i])
            {
                pick = val[i] + prev[j - wt[i]];
            }
            curr[j] = max(pick, notpick);
        }
        prev = curr;
    }
    return prev[w];
}
int solve_sopt2(int n, int w, vector<int> &wt, vector<int> &val)
{
    vector<int> prev(w + 1, 0);
    for (int i = wt[0]; i <= w; i++)
    {
        prev[i] = val[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = w; j >= 0; j--)
        {
            int notpick = prev[j];
            int pick = INT_MIN;
            if (j >= wt[i])
            {
                pick = val[i] + prev[j - wt[i]];
            }
            prev[j] = max(pick, notpick);
        }
    }
    return prev[w];
}
int main()
{
    vector<int> wt = {1, 2, 4, 5};
    vector<int> val = {5, 4, 8, 6};
    int W = 5, n = wt.size();
    cout << solve(n - 1, W, wt, val) << endl;

    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    cout << solve_mem(n - 1, W, wt, val, dp) << endl;

    cout << solve_tab(n, W, wt, val) << endl;

    cout << solve_sopt1(n, W, wt, val) << endl;

    cout << solve_sopt2(n, W, wt, val) << endl;
    return 0;
}
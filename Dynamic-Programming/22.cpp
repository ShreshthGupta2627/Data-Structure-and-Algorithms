/*We are given an array Arr with N distinct coins and a target. We have an infinite supply of each coin denomination. We need to find the number of ways we sum up the coin values to give us the target.*/
#include <bits/stdc++.h>
using namespace std;
int solve(int ind, int tar, vector<int> &den)
{
    if (ind == 0)
    {
        if (tar % den[ind] == 0)
            return 1;
        return 0;
    }
    int notpick = solve(ind - 1, tar, den);
    int pick = 0;
    if (den[ind] <= tar)
        pick = solve(ind, tar - den[ind], den);
    return pick + notpick;
}

int solve_mem(int ind, int tar, vector<int> &den, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (tar % den[ind] == 0)
            return 1;
        return 0;
    }
    if (dp[ind][tar] != -1)
        return dp[ind][tar];
    int notpick = solve(ind - 1, tar, den);
    int pick = 0;
    if (den[ind] <= tar)
        pick = solve(ind, tar - den[ind], den);
    return dp[ind][tar] = pick + notpick;
}

int solve_tab(int tar, vector<int> &den)
{
    int n = den.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
    for (int i = 0; i <= tar; i++)
    {
        if (i % den[0] == 0)
            dp[0][i] = 1;
        else
            dp[0][i] = 0;
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= tar; target++)
        {
            int notpick = dp[ind - 1][target];
            int pick = 0;
            if (den[ind] <= target)
                pick = dp[ind][target - den[ind]];
            dp[ind][target] = pick + notpick;
        }
    }
    return dp[n - 1][tar];
}

int solveSpot(int tar, vector<int> &den)
{
    int n = den.size();
    vector<int> prev(tar + 1, 0), curr(tar + 1, 0);
    for (int i = 0; i <= tar; i++)
    {
        if (i % den[0] == 0)
            prev[i] = 1;
        else
            prev[i] = 0;
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= tar; target++)
        {
            int notpick = prev[target];
            int pick = 0;
            if (den[ind] <= target)
                pick = curr[target - den[ind]];
            curr[target] = pick + notpick;
        }
        prev = curr;
    }
    return prev[tar];
}
int main()
{
    vector<int> den = {1, 5};
    int n = den.size(), tar = 5;
    cout << solve(n - 1, tar, den) << endl;

    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    cout << solve_mem(n - 1, tar, den, dp) << endl;

    cout << solve_tab(tar, den) << endl;

    cout << solveSpot(tar, den) << endl;
    return 0;
}
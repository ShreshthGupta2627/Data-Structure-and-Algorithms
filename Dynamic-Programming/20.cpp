/*We are given a target sum of ‘X’ and ‘N’ distinct numbers denoting the coin denominations. We need to tell the minimum number of coins required to reach the target sum. We can pick a coin denomination for any number of times we want.*/
#include <bits/stdc++.h>
using namespace std;
int solve(int tar, int ind, vector<int> &den)
{
    if (tar == 0)
        return 0;
    if (ind == 0)
    {
        if (tar % den[ind] == 0)
            return tar / den[ind];
        return 1e9;
    }
    int notpick = 0 + solve(tar, ind - 1, den);
    int pick = 1e9;
    if (den[ind] <= tar) 
        pick = 1 + solve(tar - den[ind], ind, den);
    return min(pick, notpick);
}

int solve_mem(int tar, int ind, vector<int> &den, vector<vector<int>> &dp)
{
    if (tar == 0)
        return 0;
    if (ind == 0)
    {
        if (tar % den[ind] == 0)
            return tar / den[ind];
        return 1e9;
    }
    if (dp[ind][tar] != -1)
        return dp[ind][tar];
    int notpick = 0 + solve(tar, ind - 1, den);
    int pick = 1e9;
    if (den[ind] <= tar)
        pick = 1 + solve(tar - den[ind], ind, den);
    return dp[ind][tar] = min(pick, notpick);
}

int solve_tab(int tar, vector<int> &den)
{
    int n = den.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
    // indx = 0 then for true
    for (int i = 0; i < tar + 1; i++)
    {
        if (i % den[0] == 0)
        {
            dp[0][i] = i / den[0];
        }
        else
        {
            dp[0][i] = 1e9;
        }
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= tar; target++)
        {
            int notpick = 0 + dp[ind - 1][target];
            int pick = 1e9;
            if (den[ind] <= target)
                pick = 1 + dp[ind][target - den[ind]];
            dp[ind][target] = min(pick, notpick);
        }
    }
    return dp[n - 1][tar];
}

int solve_spot(int tar, vector<int> &den)
{
    int n = den.size();
    vector<int> prev(tar + 1, 0), curr(tar + 1, 0);
    // indx = 0 then for true
    for (int i = 0; i < tar + 1; i++)
    {
        if (i % den[0] == 0)
        {
            prev[i] = i / den[0];
        }
        else
        {
            prev[i] = 1e9;
        }
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 0; target <= tar; target++)
        {
            int notpick = 0 + prev[target];
            int pick = 1e9;
            if (den[ind] <= target)
                pick = 1 + curr[target - den[ind]];
            curr[target] = min(pick, notpick);
        }
        prev = curr;
    }
    return prev[tar];
}
int main()
{
    int tar = 1200;
    vector<int> den = {1, 2, 5, 10, 20, 50, 100, 200, 2000};
    int n = den.size();
    cout << solve(tar, n - 1, den) << endl;

    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    cout << solve_mem(tar, n - 1, den, dp) << endl;

    cout << solve_tab(tar, den) << endl;
    cout << solve_spot(tar, den) << endl;

    return 0;
}
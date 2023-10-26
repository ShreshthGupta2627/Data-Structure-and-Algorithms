/*A thief wants to rob a store. He is carrying a bag of capacity W. The store has ‘n’ items of infinite supply. Its weight is given by the ‘wt’ array and its value by the ‘val’ array. He can either include an item in its knapsack or exclude it but can’t partially have it as a fraction. We need to find the maximum value of items that the thief can steal. He can take a single item any number of times he wants and put it in his knapsack.*/

#include <bits/stdc++.h>
using namespace std;
int solve(int ind, int cap, vector<int> &wt, vector<int> &val)
{
    if (ind == 0)
    {
        return (cap / wt[ind]) * val[ind];
    }
    int notpick = solve(ind - 1, cap, wt, val);
    int pick = -1e9;
    if (cap >= wt[ind])
    {
        pick = val[ind] + solve(ind, cap - wt[ind], wt, val);
    }
    return max(pick, notpick);
}

int solve_mem(int ind, int cap, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return (cap / wt[ind]) * val[ind];
    }
    if (dp[ind][cap] != -1)
        return dp[ind][cap];
    int notpick = solve(ind - 1, cap, wt, val);
    int pick = -1e9;
    if (cap >= wt[ind])
    {
        pick = val[ind] + solve(ind, cap - wt[ind], wt, val);
    }
    return dp[ind][cap] = max(pick, notpick);
}

int solve_tab(int n, int cap, vector<int> &wt, vector<int> &val)
{
    vector<vector<int>> dp(n, vector<int>(cap + 1, 0));
    for (int i = 0; i <= cap; i++)
    {
        dp[0][i] = (i / wt[0]) * val[0];
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int tar = 0; tar <= cap; tar++)
        {
            int notpick = dp[ind - 1][tar];
            int pick = -1e9;
            if (tar >= wt[ind])
            {
                pick = val[ind] + dp[ind][tar - wt[ind]];
            }
            dp[ind][tar] = max(pick, notpick);
        }
    }
    return dp[n - 1][cap];
}

int solveSpot(int n, int cap, vector<int> &wt, vector<int> &val)
{
    vector<int> curr(cap + 1, 0), prev(cap + 1, 0);
    for (int i = 0; i <= cap; i++)
    {
        prev[i] = (i / wt[0]) * val[0];
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int tar = 0; tar <= cap; tar++)
        {
            int notpick = prev[tar];
            int pick = -1e9;
            if (tar >= wt[ind])
            {
                pick = val[ind] + curr[tar - wt[ind]];
            }
            curr[tar] = max(pick, notpick);
        }
        prev = curr;
    }
    return prev[cap];
}
int main()
{
    vector<int> wt = {2, 4, 6};
    vector<int> val = {5, 11, 13};
    int cap = 10;
    int n = wt.size();
    cout << solve(n - 1, cap, wt, val) << endl;

    vector<vector<int>> dp(n, vector<int>(cap + 1, -1));
    cout << solve_mem(n - 1, cap, wt, val, dp) << endl;

    cout << solve_tab(n, cap, wt, val) << endl;

    cout << solveSpot(n, cap, wt, val) << endl;
    return 0;
}
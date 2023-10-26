// Subset sum equal to target
/*
You are given an array/list ‘ARR’ of ‘N’ positive integers and an integer ‘K’. Your task is to check if there exists a subset in ‘ARR’ with a sum equal to ‘K’.

Note: Return true if there exists a subset with sum equal to ‘K’. Otherwise, return false.

Ex:
If ‘ARR’ is {1,2,3,4} and ‘K’ = 4, then there exists 2 subsets with sum = 4. These are {1,3} and {4}. Hence, return true.
*/
#include <bits/stdc++.h>
using namespace std;
bool solve(int indx, int target, vector<int> &v)
{
    if (target == 0)
    {
        return true;
    }
    if (indx == 0)
    {
        return (v[indx] == target);
    }
    bool notpick = solve(indx - 1, target, v);
    bool pick = target >= v[indx] ? solve(indx - 1, target - v[indx], v) : false;
    return (pick || notpick);
}
bool solve_with_memoization(int indx, int target, vector<int> &v, vector<vector<int>> &dp)
{
    if (target == 0)
    {
        return true;
    }
    if (indx == 0)
    {
        return (v[indx] == target);
    }
    if (dp[indx][target] != -1)
        return dp[indx][target];
    bool notpick = solve_with_memoization(indx - 1, target, v, dp);
    bool pick = target >= v[indx] ? solve_with_memoization(indx - 1, target - v[indx], v, dp) : false;
    return dp[indx][target] = pick || notpick;
}
bool solve_with_tabulation(int ind, int tar, vector<int> &v)
{
    vector<vector<bool>> dp(ind, vector<bool>(tar + 1, 0));
    for (int i = 0; i < ind; i++)
    {
        dp[i][0] = true;
    }
    if (v[0] <= tar)
        dp[0][v[0]] = true;
    for (int indx = 1; indx < ind; indx++)
    {
        for (int target = 1; target <= tar; target++)
        {
            bool notTake = dp[indx - 1][target];
            bool take = (v[indx] <= target) ? dp[indx - 1][target - v[indx]] : false;
            dp[indx][target] = take || notTake;
        }
    }
    return dp[ind - 1][tar];
}
bool solve_with_spaceOptimization(int ind, int tar, vector<int> &v)
{
    // vector<vector<bool>> dp(ind, vector<bool>(tar + 1, 0));
    vector<bool> curr(tar + 1, 0);
    vector<bool> prev(tar + 1, 0);
    curr[0] = true;
    if (v[0] <= tar)
        prev[v[0]] = true;
    for (int indx = 1; indx < ind; indx++)
    {
        for (int target = 1; target <= tar; target++)
        {
            bool notTake = prev[target];
            bool take = (v[indx] <= target) ? prev[target - v[indx]] : false;
            curr[target] = take || notTake;
        }
        prev = curr;
    }
    return prev[tar];
}
int main()
{
    vector<int> v = {1, 2, 3, 4};
    int n = v.size();
    int target = 4;
    cout << solve(n - 1, target, v) << endl;

    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    cout << solve_with_memoization(n - 1, target, v, dp) << endl;

    cout << solve_with_tabulation(n, target, v) << endl;
    cout << solve_with_spaceOptimization(n, target, v) << endl;
    return 0;
}
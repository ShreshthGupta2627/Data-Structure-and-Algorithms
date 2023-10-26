/*You are given an array 'ARR' of 'N' positive integers. Your task is to find if we can partition the given array into two subsets such that the sum of elements in both subsets is equal.

For example, let’s say the given array is [2, 3, 3, 3, 4, 5], then the array can be partitioned as [2, 3, 5], and [3, 3, 4] with equal sum 10.
*/
#include <bits/stdc++.h>
using namespace std;
bool solve(int indx, int target, vector<int> &v, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (indx == 0)
        return target == v[indx];
    if (dp[indx][target] != -1)
        return dp[indx][target];
    bool notPick = solve(indx - 1, target, v, dp);
    bool Pick = (v[indx] <= target) ? solve(indx - 1, target - v[indx], v, dp) : false;
    return dp[indx][target] = Pick || notPick;
}
bool solve_tab(int n, int k, vector<int> &v)
{
    vector<vector<int>> dp(n, vector<int>(k, 0));
    for (int indx = 0; indx < n; indx++)
    {
        dp[indx][0] = true;
    }
    if (v[0] <= k)
        dp[0][v[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            bool notTake = dp[i - 1][j];
            bool take = (v[i] <= j) ? dp[i - 1][j - v[i]] : false;
            dp[i][j] = take || notTake;
        }
    }
    return dp[n - 1][k];
}
int main()
{
    vector<int> v = {2, 3, 3, 3, 4, 5};
    int n = v.size();
    int sum = 0;
    for (auto &it : v)
    {
        sum += it;
    }
    if (sum & 1)
        cout << "No" << endl;
    else
    {
        sum >> 1;
        vector<vector<int>> dp(n, vector<int>(sum, -1));
        if (solve_tab(n, sum, v))
            cout << "Yes" << endl;
    }
    return 0;
}
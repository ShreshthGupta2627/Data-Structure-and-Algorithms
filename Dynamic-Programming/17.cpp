/* Count subset with sum k
You are given an array (0-based indexing) of positive integers and you have to tell how many different ways of selecting the elements from the array are there such that the sum of chosen elements is equal to the target number “tar”.
Two ways are considered different if sets of indexes of elements chosen by these ways are different.*/
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &v, int ind, int s)
{
    if (ind == 0)
    {
        if (s == 0 && v[0] == 0)
            return 2;
        if (s == 0 || s == v[0])
            return 1;
        return 0;
    }
    int pick = 0, notpick;
    notpick = solve(v, ind - 1, s);
    if (v[ind] <= s)
        pick = solve(v, ind - 1, s - v[ind]);
    return pick + notpick;
}
int solve_mem(vector<int> &v, int ind, int s, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (s == 0 && v[0] == 0)
            return 2;
        if (s == 0 || s == v[0])
            return 1;
        return 0;
    }
    if (dp[ind][s] != -1)
        return dp[ind][s];
    int pick = 0, notpick;
    notpick = solve(v, ind - 1, s);
    if (v[ind] <= s)
        pick = solve(v, ind - 1, s - v[ind]);
    return dp[ind][s] = pick + notpick;
}
int solve_tab(vector<int> &v, int n, int s)
{
    vector<vector<int>> dp(v.size(), vector<int>(s + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    if (v[0] <= s)
        dp[0][v[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int s1 = 0; s1 <= s; s1++)
        {
            int notpick = dp[i - 1][s1];
            int pick = 0;
            if (v[i] <= s1)
                pick = dp[i][s1 - v[i]];
            dp[i][s1] = pick + notpick;
        }
    }
    return dp[n - 1][s];
}
int solve_Sopt(vector<int> &v, int n, int s)
{
    // vector<vector<int>> dp(v.size(), vector<int>(s + 1, 0));
    vector<int> prev(s + 1, 0), curr(s + 1, 0);
    prev[0] = 1;
    curr[0] = 1;
    if (v[0] <= s)
        prev[v[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int s1 = 1; s1 <= s; s1++)
        {
            int notpick = prev[s1];
            int pick = 0;
            if (v[i] <= s1)
                pick = curr[s1 - v[i]];
            curr[s1] = pick + notpick;
        }
        prev = curr;
    }
    return prev[s];
}
int main()
{
    vector<int> v = {1, 2, 3};
    int n = v.size() - 1, sum = 3;
    cout << solve(v, n, sum) << endl;

    vector<vector<int>> dp(v.size(), vector<int>(sum + 1, -1));
    cout << solve_mem(v, n, sum, dp) << endl;

    cout << solve_tab(v, n + 1, sum) << endl;

    cout << solve_Sopt(v, n + 1, sum) << endl;
    return 0;
}
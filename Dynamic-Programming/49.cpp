// Burst Ballons
/*You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.
If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.
Return the maximum coins you can collect by bursting the balloons wisely.*/

#include <bits/stdc++.h>
using namespace std;
int rec(int i, int j, vector<int> &v)
{
    if (i > j)
    {
        return 0;
    }
    int maxx = INT_MIN;
    // Anyone can be the last one to get busted :. loop
    for (int ind = i; ind <= j; ind++)
    {
        int cost = v[i - 1] * v[ind] * v[j + 1] + rec(i, ind - 1, v) + rec(ind + 1, j, v);
        maxx = max(maxx, cost);
    }
    return maxx;
}
int mem(int i, int j, vector<int> &v, vector<vector<int>> &dp)
{
    if (i > j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    int maxx = INT_MIN;
    // Anyone can be the last one to get busted :. loop
    for (int ind = i; ind <= j; ind++)
    {
        int cost = v[i - 1] * v[ind] * v[j + 1] + mem(i, ind - 1, v, dp) + mem(ind + 1, j, v, dp);
        maxx = max(maxx, cost);
    }
    return dp[i][j] = maxx;
}

int tab(vector<int> &v)
{
    int n = v.size() - 2;
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int i = n; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            // This cond will cover base case
            if (i > j)
                continue;
            int maxx = INT_MIN;
            // Anyone can be the last one to get busted :. loop
            for (int ind = i; ind <= j; ind++)
            {
                int cost = v[i - 1] * v[ind] * v[j + 1] + dp[i][ind - 1] + dp[ind + 1][j];
                maxx = max(maxx, cost);
            }
            dp[i][j] = maxx;
        }
    }
    return dp[1][n];
}
int main()
{
    vector<int> v = {3, 1, 5, 8};
    int n = v.size();
    v.insert(v.begin(), 1);
    v.push_back(1);
    cout << rec(1, n, v) << endl;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    cout << mem(1, n, v, dp) << endl;

    cout << tab(v) << endl;
    return 0;
}
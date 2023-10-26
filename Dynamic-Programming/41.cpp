// Longest incresing subsequence
// Given an integer array , return the length of the longest strictly increasing subsequence
#include <bits/stdc++.h>
using namespace std;
int rec(int ind, int prev_ind, vector<int> &a)
{
    if (ind == a.size())
        return 0;
    int Pick = INT_MIN, notPick = INT_MIN;
    // Not pick will change length by 0
    notPick = 0 + rec(ind + 1, prev_ind, a);
    if (prev_ind == -1 || a[ind] > a[prev_ind])
        Pick = 1 + rec(ind + 1, ind, a);
    return max(Pick, notPick);
}
int mem(int ind, int prev_ind, vector<int> &a, vector<vector<int>> &dp)
{
    if (ind == a.size())
        return 0;
    if (dp[ind][prev_ind + 1] != -1)
        return dp[ind][prev_ind + 1];

    int Pick = INT_MIN, notPick = INT_MIN;

    notPick = 0 + rec(ind + 1, prev_ind, a);
    if (prev_ind == -1 || a[ind] > a[prev_ind])
    {
        Pick = 1 + rec(ind + 1, ind, a);
    }
    return dp[ind][prev_ind + 1] = max(Pick, notPick);
}

int tab(vector<int> &a)
{
    int n = a.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][n] = 0;
    }
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
        {
            // the prev index places will have + 1 to shift
            int Pick = INT_MIN, notPick = INT_MIN;
            notPick = 0 + dp[ind + 1][prev_ind + 1];
            if (prev_ind == -1 || a[ind] > a[prev_ind])
            {
                Pick = 1 + dp[ind + 1][ind + 1];
            }
            dp[ind][prev_ind + 1] = max(Pick, notPick);
        }
    }
    return dp[0][-1 + 1];
}

int sOpt(vector<int> &a)
{
    int n = a.size();
    vector<int> next(n + 1, 0), curr(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        next[n] = 0;
    }
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev_ind = ind - 1; prev_ind >= -1; prev_ind--)
        {
            // the prev index places will have + 1 to shift
            int Pick = INT_MIN, notPick = INT_MIN;
            notPick = 0 + next[prev_ind + 1];
            if (prev_ind == -1 || a[ind] > a[prev_ind])
            {
                Pick = 1 + next[ind + 1];
            }
            curr[prev_ind + 1] = max(Pick, notPick);
        }
        next = curr;
    }
    return next[-1 + 1];
}

int tab_more_optimized(vector<int> &a)
{
    int n = a.size();
    // 1 is there ncz everyone itself must be in LIS
    vector<int> dp(n, 1);
    for (int ind = 0; ind < n; ind++)
    {
        for (int prev = 0; prev < ind; prev++)
        {
            if (a[prev] < a[ind])
            {
                dp[ind] = max(dp[ind], 1 + dp[prev]);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int tab_with_generation_oF_LIS(vector<int> &a)
{
    int n = a.size();
    // 1 is there ncz everyone itself must be in LIS
    vector<int> dp(n, 1), backtrack(n, 0);
    for (int i = 0; i < n; i++)
    {
        backtrack[i] = i;
    }
    for (int ind = 0; ind < n; ind++)
    {
        for (int prev = 0; prev < ind; prev++)
        {
            if (a[prev] < a[ind])
            {
                if (dp[ind] < 1 + dp[prev])
                {
                    backtrack[ind] = prev;
                }
                dp[ind] = max(dp[ind], 1 + dp[prev]);
            }
        }
    }
    int len_lis = *max_element(dp.begin(), dp.end());
    int Last_Ind = max_element(dp.begin(), dp.end()) - dp.begin();
    vector<int> lis;
    lis.push_back(a[Last_Ind]);
    while (backtrack[Last_Ind] != Last_Ind)
    {
        Last_Ind = backtrack[Last_Ind];
        lis.push_back(a[Last_Ind]);
    }
    reverse(lis.begin(), lis.end());
    for (auto &it : lis)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}

int main()
{
    vector<int> a = {5, 4, 11, 1, 16, 8};
    int n = a.size();

    cout << rec(0, -1, a) << endl;

    // To memoize we need to shift prev_ind from -1 to 0 :. +1 in dp state
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    cout << mem(0, -1, a, dp) << endl;

    cout << tab(a) << endl;

    cout << sOpt(a) << endl;

    cout << tab_more_optimized(a) << endl;

    tab_with_generation_oF_LIS(a);
    return 0;
}
// Partition with given sum

/*
Given an array ‘ARR’, partition it into two subsets (possibly empty) such that their union is the original array. Let the sum of the elements of these two subsets be ‘S1’ and ‘S2’.
Given a difference ‘D’, count the number of partitions in which ‘S1’ is greater than or equal to ‘S2’ and the difference between ‘S1’ and ‘S2’ is equal to ‘D’. Since the answer may be too large, return it modulo ‘10^9 + 7’.
If ‘Pi_Sj’ denotes the Subset ‘j’ for Partition ‘i’. Then, two partitions P1 and P2 are considered different if:

1) P1_S1 != P2_S1 i.e, at least one of the elements of P1_S1 is different from P2_S2.
2) P1_S1 == P2_S2, but the indices set represented by P1_S1 is not equal to the indices set of P2_S2. Here, the indices set of P1_S1 is formed by taking the indices of the elements from which the subset is formed.

Note: sum of element of empty sybset is assumed to be 0

Refer to the example below for clarification.
If N = 4, D = 3, ARR = {5, 2, 5, 1}
There are only two possible partitions of this array.
Partition 1: {5, 2, 1}, {5}. The subset difference between subset sum is: (5 + 2 + 1) - (5) = 3
Partition 2: {5, 2, 1}, {5}. The subset difference between subset sum is: (5 + 2 + 1) - (5) = 3
These two partitions are different because, in the 1st partition, S1 contains 5 from index 0, and in the 2nd partition, S1 contains 5 from index 2.
*/

#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &v, vector<vector<int>> &dp, int ind, int s)
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
    notpick = solve(v, dp, ind - 1, s);
    if (v[ind] <= s)
        pick = solve(v, dp, ind - 1, s - v[ind]);
    return dp[ind][s] = pick + notpick;
}
int call_solve(vector<int> &v, int n, int d)
{
    int totsum = 0;
    for (auto &it : v)
        totsum += it;
    if (totsum - d < 0 || (totsum - d) & 1)
        return 0;
    vector<vector<int>> dp(n + 1, vector<int>((totsum - d) / 2 + 1, -1));
    return solve(v, dp, n, (totsum - d) / 2);
}

int solve_tab(vector<int> &v, int tar)
{
    int n = v.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
    if (v[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;
    // v[0]!=0
    if (v[0] != 0 && v[0] <= tar)
        dp[0][v[0]] = 1;
    for (int ind = 1; ind < n; ind++)
    {
        for (int sum = 0; sum <= tar; sum++)
        {
            int nottake = dp[ind - 1][sum];
            int take = 0;
            if (v[ind] <= sum)
                take = dp[ind - 1][sum - v[ind]];
            dp[ind][sum] = take + nottake;
        }
    }
    return dp[n - 1][tar];
}

int call_solve_tab(vector<int> &v, int n, int d)
{
    int totsum = 0;
    for (auto &it : v)
        totsum += it;
    if (totsum - d < 0 || (totsum - d) & 1)
        return 0;
    return solve_tab(v, (totsum - d) / 2);
}

int solve_sopt(vector<int> &v, int tar)
{
    int n = v.size();
    vector<int> prev(tar + 1, 0), curr(tar + 1, 0);
    if (v[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;
    // v[0]!=0
    if (v[0] != 0 && v[0] <= tar)
        prev[v[0]] = 1;
    for (int ind = 1; ind < n; ind++)
    {
        for (int sum = 0; sum <= tar; sum++)
        {
            int nottake = prev[sum];
            int take = 0;
            if (v[ind] <= sum)
                take = prev[sum - v[ind]];
            curr[sum] = take + nottake;
        }
        prev = curr;
    }
    return prev[tar];
}

int call_solve_sopt(vector<int> &v, int n, int d)
{
    int totsum = 0;
    for (auto &it : v)
        totsum += it;
    if (totsum - d < 0 || (totsum - d) & 1)
        return 0;
    return solve_sopt(v, (totsum - d) / 2);
}
int main()
{
    vector<int> v = {5, 2, 5, 1};
    int n = v.size() - 1, d = 3;
    cout << call_solve(v, n, d) << endl;
    cout << call_solve_tab(v, n, d) << endl;
    cout << call_solve_sopt(v, n, d) << endl;
    return 0;
}
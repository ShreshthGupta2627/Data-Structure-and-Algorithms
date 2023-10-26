/*
You are given an array containing N non-negative integers. Your task is to partition this array into two subsets such that the absolute difference between subset sums is minimum.
You just need to find the minimum absolute difference considering any valid division of the array elements.

1. Each element of the array should belong to exactly one of the subset
2. Subsets need not be contiguous always. For example, for the array : {1,2,3}, some of the possible divisions are a) {1,2} and {3}  b) {1,3} and {2}.
3. Subset-sum is the sum of all the elements in that subset.
*/
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &v, int n)
{
    int totSum = 0;
    for (int i = 0; i < n; i++)
    {
        totSum += v[i];
    }
    int k = totSum;
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    if (v[0] <= k)
        dp[0][v[0]] = 1;
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool nottake = dp[ind - 1][target];
            bool take = false;
            if (v[ind] <= target)
                take = dp[ind - 1][target - v[ind]];
            dp[ind][target] = take || nottake;
        }
    }

    // d[n-1][col]  -> 0.......totsum
    int minn = 1e9;
    for (int s1 = 0; s1 <= totSum; s1++)
    {
        if (dp[n - 1][s1] == true)
            minn = min(minn, abs((totSum - s1) - s1));
    }
    return minn;
}
int main()
{
    vector<int> v = {1, 2, 100};
    cout << solve(v, v.size()) << endl;
    return 0;
}
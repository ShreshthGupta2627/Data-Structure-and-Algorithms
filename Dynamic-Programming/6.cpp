/*You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
*/
#include <bits/stdc++.h>
using namespace std;
int f(int ind, vector<int> &nums)
{
    if (ind == 0)
        return nums[ind];
    if (ind < 0)
        return 0;
    int pick = nums[ind] + f(ind - 2, nums);
    int notPick = 0 + f(ind - 1, nums);
    return max(pick, notPick);
}
int f_with_memoization(int ind, vector<int> &nums, vector<int> &dp)
{
    if (ind == 0)
        return nums[ind];
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int pick = nums[ind] + f_with_memoization(ind - 2, nums, dp);
    int notPick = 0 + f_with_memoization(ind - 1, nums, dp);
    return dp[ind] = max(pick, notPick);
}
int f_with_tabulation(int ind, vector<int> &nums)
{
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int neg = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        int take = nums[i];
        if (i > 1)
            take += dp[i - 2];
        int not_take = 0 + dp[i - 1];
        dp[i] = max(take, not_take);
    }
    return dp[ind];
}
int f_space_optimized(int ind, vector<int> &nums)
{
    int n = nums.size();
    int prev = nums[0], prev2 = 0, curi = 0;
    for (int i = 1; i < n; i++)
    {
        int take = nums[i];
        if (i > 1)
            take += prev2;
        int not_take = 0 + prev;
        curi = max(take, not_take);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}
int main()
{
    vector<int> v = {2, 3, 2};
    vector<int> t1, t2;
    for (int i = 0; i < v.size(); i++)
    {
        if (i != 0)
            t1.push_back(v[i]);
        if (i != v.size() - 1)
            t2.push_back(v[i]);
    }
    cout << max(f(0, t1), f(0, t2)) << endl;

    vector<int> dp1(v.size(), -1);
    vector<int> dp2(v.size(), -1);
    cout << max(f_with_memoization(0, t1, dp1), f_with_memoization(0, t2, dp2)) << endl;

    cout << max(f_with_tabulation(0, t1), f_with_tabulation(0, t2)) << endl;

    cout << max(f_space_optimized(0, t1), f_space_optimized(0, t2)) << endl;
    return 0;
}
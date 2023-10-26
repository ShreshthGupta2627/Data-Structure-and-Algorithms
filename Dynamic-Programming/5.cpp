// Maximum sum of non-adjacent element
/*You are given an a array of list of no 'n' integer you are supposed to return the maximum sum of the subsequence with the constraint that no two elements are adjacent in the given array list*/
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
int maximumNonAdjacentSum(vector<int> &nums)
{
    int n = nums.size();
    return f(n - 1, nums);
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
    vector<int> nums = {4, 6, 3, 5};
    vector<int> dp(nums.size(), -1);
    cout << maximumNonAdjacentSum(nums) << endl;
    cout << f_with_memoization(nums.size() - 1, nums, dp) << endl;
    cout << f_with_tabulation(nums.size() - 1, nums) << endl;
    cout << f_space_optimized(nums.size() - 1, nums);
    return 0;
}
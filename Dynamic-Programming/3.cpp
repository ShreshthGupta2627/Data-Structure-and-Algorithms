// 1 --> n jumping 1,2 step at once total no of diff ways
#include <bits/stdc++.h>
using namespace std;
int cost(int indx, int *a)
{
    if (indx == 0)
        return 0; // 0 --> 0 cost = 0
    int left, right = INT_MAX;
    left = cost(indx - 1, a) + abs(a[indx] - a[indx - 1]);
    if (indx > 1)
        right = cost(indx - 2, a) + abs(a[indx] - a[indx - 2]);
    return min(left, right);
}
int cost_with_memoization(int indx, int *a, vector<int> &dp)
{
    if (indx == 0)
        return 0;
    // 0 --> 0 cost = 0
    if (dp[indx] != -1)
        return dp[indx];
    int left, right = INT_MAX;
    left = cost_with_memoization(indx - 1, a, dp) + abs(a[indx] - a[indx - 1]);
    if (indx > 1)
        right = cost_with_memoization(indx - 2, a, dp) + abs(a[indx] - a[indx - 2]);
    dp[indx] = min(left, right);
    return dp[indx];
}
int cost_with_tabulation(int indx, int *a)
{
    vector<int> dp(indx + 1, 0);
    dp[0] = 0;
    for (int i = 1; i <= indx; i++)
    {
        int first, second = INT_MAX;
        first = dp[i - 1] + abs(a[i] - a[i - 1]);
        if (i > 1)
            second = dp[i - 2] + abs(a[i] - a[i - 2]);
        dp[i] = min(first, second);
    }
    return dp[indx];
}
int cost_space_optimized(int n, int indx, int *a)
{
    int prev = 0, prev2 = 0, curr;
    for (int i = 1; i < indx + 1; i++)
    {
        int first, second = INT_MAX;
        first = prev + abs(a[i] - a[i - 1]);
        if (i > 1)
            second = prev2 + abs(a[i] - a[i - 2]);
        curr = min(first, second);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}
int main()
{
    int n;
    n = 4;
    int a[n] = {10, 20, 30, 10};
    // int a[n] = {30, 10, 60, 10, 60, 50};
    vector<int> dp(n, -1);
    int l = cost(3, a);
    cout << l << endl;
    cout << cost_with_memoization(3, a, dp) << endl;
    cout << cost_with_tabulation(3, a) << endl;
    cout << cost_space_optimized(4, 3, a);
    return 0;
}

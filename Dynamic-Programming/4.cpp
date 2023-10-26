// 1 --> n jumping 1.......k step at once total no of diff ways
#include <bits/stdc++.h>
using namespace std;
int cost(int n, int indx, int *A, int k)
{
    if (indx == 0)
        return 0;
    int minSteps = INT_MAX;
    for (int j = 1; j <= k; j++)
    {
        if (indx - j >= 0)
        {
            int jump = cost(n, indx - j, A, k) + abs(A[indx] - A[indx - j]);
            minSteps = min(minSteps, jump);
        }
        else
        {
            break;
        }
    }
    return minSteps;
}
int cost_with_memoization(int n, int indx, int *A, vector<int> &dp, int k)
{
    if (indx == 0)
        return 0;
    if (dp[indx] != -1)
        return dp[indx];
    int minStep = INT_MAX, jump;
    for (int j = 1; j <= k; j++)
    {
        if (indx - j >= 0)
        {
            jump = cost_with_memoization(n, indx - j, A, dp, k) + abs(A[indx] - A[indx - j]);
            minStep = min(minStep, jump);
        }
    }
    dp[indx] = minStep;
    return dp[indx];
}
int cost_with_tabulation(int indx, int *A, int k)
{
    int dp[indx + 1] = {0};
    for (int i = 1; i <= indx; i++)
    {
        int minStep = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                int jump = dp[i - j] + abs(A[i] - A[i - j]);
                minStep = min(minStep, jump);
            }
        }
        dp[i] = minStep;
    }
    return dp[indx];
}
int main()
{
    int n = 4, k = 2;
    int A[n] = {10, 20, 30, 10};
    vector<int> dp(n, -1);
    cout << cost(n, 3, A, 2) << endl;
    cout << cost_with_memoization(n, 3, A, dp, k) << endl;
    cout << cost_with_tabulation(3, A, k) << endl;

    return 0;
}
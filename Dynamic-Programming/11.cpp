/*You are given a triangular array/list 'TRIANGLE'. Your task is to return the minimum path sum to reach from the top to the bottom row.
The triangle array will have N rows and the i-th row, where 0 <= i < N will have i + 1 elements.
You can move only to the adjacent number of row below each step. For example, if you are at index j in row i, then you can move to i or i + 1 index in row j + 1 in each step.
For Example :
If the array given is 'TRIANGLE' = [[1], [2,3], [3,6,7], [8,9,6,1]] the triangle array will look like:
1
2,3
3,6,7
8,9,6,10
For the given triangle array the minimum sum path would be 1->2->3->8. Hence the answer would be 14*/
#include <bits/stdc++.h>
using namespace std;
int solve(int i, int j, vector<vector<int>> &a)
{
    if (i == a.size() - 1)
        return a[i][j];
    int down = a[i][j] + solve(i + 1, j, a);
    int digonal = a[i][j] + solve(i + 1, j + 1, a);
    return min(down, digonal);
    // TC : 2^(1+2+3+4+ ..... +n) i.e exponential
    // SC : O(n) stack space
}
int solve_memoization(int i, int j, vector<vector<int>> &a, vector<vector<int>> &dp)
{
    if (i == a.size() - 1)
        return dp[i][j] = a[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int down = a[i][j] + solve(i + 1, j, a);
    int digonal = a[i][j] + solve(i + 1, j + 1, a);
    return dp[i][j] = min(down, digonal);
    // TC :O(n*n)
    // SC :O(n) + O(n*n)
}
int solve_tabulation(vector<vector<int>> &a)
{
    int n = a.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int j = 0; j < n; j++)
    {
        dp[n - 1][j] = a[n - 1][j];
    }
    // n-1 is already coverd :. we can start from n-2
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = a[i][j] + dp[i + 1][j];
            int diagonal = a[i][j] + dp[i + 1][j + 1];
            dp[i][j] = min(down, diagonal);
        }
    }
    return dp[0][0];
    // TC : O(n*n)
    // SC : O(n*n)
}
int solve_spaceOptimised(vector<vector<int>> &a)
{
    int n = a.size();
    vector<int> front(n, 0), curr(n, 0);
    for (int j = 0; j < n; j++)
    {
        front[j] = a[n - 1][j];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            int down = a[i][j] + front[j];
            int diagonal = a[i][j] + front[j + 1];
            curr[j] = min(down, diagonal);
        }
        front = curr;
    }
    return front[0];
    // TC : O(n*n)
    // SC : O(n)
}
int main()
{
    vector<vector<int>> v = {{1}, {2, 3}, {3, 6, 7}, {8, 9, 6, 10}};
    cout << solve(0, 0, v) << endl;
    vector<vector<int>> dp(v.size(), vector<int>(v.size(), -1));
    cout << solve_memoization(0, 0, v, dp) << endl;
    cout << solve_tabulation(v) << endl;
    cout << solve_spaceOptimised(v) << endl;
    return 0;
}
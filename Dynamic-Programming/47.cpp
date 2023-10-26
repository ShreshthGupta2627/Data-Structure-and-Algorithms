// Matrix chain multiplication

/*Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.
The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i])*/

#include <bits/stdc++.h>
using namespace std;
int MinMulOpr(int start, int end, vector<int> &dim)
{
    int n = dim.size();
    // In base case if only 1 matrix left we will do 0 multiplication
    if (start == end)
        return 0;
    int min_ans = 1e9;
    for (int partition_idx = start; partition_idx < end; partition_idx++)
    {
        int cnt_mul = dim[start - 1] * dim[partition_idx] * dim[end] + MinMulOpr(start, partition_idx, dim) + MinMulOpr(partition_idx + 1, end, dim);
        min_ans = min(min_ans, cnt_mul);
    }
    return min_ans;
}

int MinMulOpr_mem(int start, int end, vector<int> &dim, vector<vector<int>> &dp)
{
    int n = dim.size();
    // In base case if only 1 matrix left we will do 0 multiplication
    if (start == end)
        return 0;
    if (dp[start][end] != -1)
        return dp[start][end];
    int min_ans = 1e9;
    for (int partition_idx = start; partition_idx < end; partition_idx++)
    {
        int cnt_mul = dim[start - 1] * dim[partition_idx] * dim[end] + MinMulOpr_mem(start, partition_idx, dim, dp) + MinMulOpr_mem(partition_idx + 1, end, dim, dp);
        min_ans = min(min_ans, cnt_mul);
    }
    return dp[start][end] = min_ans;
}

int tab(vector<int> &dim)
{
    int n = dim.size();
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < n; i++)
    {
        dp[i][i] = 0;
    }
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            int min_ans = 1e9;
            for (int k = i; k < j; k++)
            {
                int cnt_mul = dim[i - 1] * dim[k] * dim[j] + dp[i][k] + dp[k + 1][j];
                min_ans = min(min_ans, cnt_mul);
            }
            dp[i][j] = min_ans;
        }
    }
    return dp[1][n - 1];
}
int main()
{
    // A : 10 X 20 , B : 20 X 30 , C : 30 X 40 , D : 40 X 50  for 4 matrix we store 4 + 1 values only
    vector<int> dim = {10, 20, 30, 40, 50};
    int n = dim.size();
    cout << MinMulOpr(1, n - 1, dim) << endl;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << MinMulOpr_mem(1, n - 1, dim, dp) << endl;
    cout << tab(dim) << endl;
    return 0;
}
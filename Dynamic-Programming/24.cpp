/*We are given a rod of size ‘N’. It can be cut into pieces. Each length of a piece has a particular price given by the price array. Our task is to find the maximum revenue that can be generated by selling the rod after cutting( if required) into pieces.*/

#include <bits/stdc++.h>
using namespace std;
int solve(int ind, int len, vector<int> &price)
{
    if (ind == 0)
        return (len / (ind + 1)) * price[ind];
    // ind+1 is rod lengt
    int notpick = solve(ind - 1, len, price);
    int pick = INT_MIN;
    int rodlen = ind + 1;
    if (rodlen <= len)
        pick = price[ind] + solve(ind, len - rodlen, price);
    return max(pick, notpick);
}

int solve_mem(int ind, int len, vector<int> &price, vector<vector<int>> &dp)
{
    if (ind == 0)
        return (len / (ind + 1)) * price[ind];
    // ind+1 is rod lengt
    if (dp[ind][len] != -1)
        return dp[ind][len];
    int notpick = solve(ind - 1, len, price);
    int pick = INT_MIN;
    int rodlen = ind + 1;
    if (rodlen <= len)
        pick = price[ind] + solve(ind, len - rodlen, price);
    return dp[ind][len] = max(pick, notpick);
}

int solve_tab(int n, int len, vector<int> &price)
{
    vector<vector<int>> dp(n, vector<int>(len + 1, 0));
    for (int i = 0; i <= len; i++)
    {
        dp[0][i] = i * price[0];
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int length = 0; length <= len; length++)
        {
            int notpick = dp[ind - 1][length];
            int pick = INT_MIN;
            int rodlen = ind + 1;
            if (rodlen <= length)
                pick = price[ind] + dp[ind][length - rodlen];
            dp[ind][length] = max(pick, notpick);
        }
    }
    return dp[n - 1][len];
}

int solveSpot(int len, vector<int> &price)
{
    vector<int> curr(len + 1, 0), prev(len + 1, 0);
    for (int i = 0; i <= len; i++)
    {
        prev[i] = i * price[0];
    }
    // n==len
    for (int ind = 1; ind < len; ind++)
    {
        for (int length = 0; length <= len; length++)
        {
            int notpick = prev[length];
            int pick = INT_MIN;
            int rodlen = ind + 1;
            if (rodlen <= length)
                pick = price[ind] + curr[length - rodlen];
            curr[length] = max(pick, notpick);
        }
        prev = curr;
    }
    return prev[len];
}
int main()
{
    vector<int> price = {2, 5, 7, 8, 10};
    int n = price.size();
    cout << solve(n - 1, n, price) << endl;

    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    cout << solve_mem(n - 1, n, price, dp) << endl;

    cout << solve_tab(n, n, price) << endl;

    cout << solveSpot(n, price) << endl;
    return 0;
}
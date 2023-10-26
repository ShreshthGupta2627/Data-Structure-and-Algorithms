/*We are given an array ‘ARR’ of size ‘N’ and a number ‘Target’. Our task is to build an expression from the given array where we can place a ‘+’ or ‘-’ sign in front of an integer. We want to place a sign in front of every integer of the array and get our required target. We need to count the number of ways in which we can achieve our required target.*/

#include <bits/stdc++.h>
using namespace std;
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
// d= target
int call_solve_tab(vector<int> &v, int n, int d)
{
    int totsum = 0;
    for (auto &it : v)
        totsum += it;
    if (totsum - d < 0 || (totsum - d) & 1)
        return 0;
    return solve_tab(v, (totsum - d) / 2);
}
int main()
{
    vector<int> v = {1, 2, 3, 1};
    int n = v.size() - 1, d = 3;
    cout << call_solve_tab(v, n, d) << endl;
    return 0;
}
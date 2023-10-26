/*Find longest common subsequence in two given string*/
#include <bits/stdc++.h>
using namespace std;
int rec(string s1, string s2, int ind1, int ind2)
{
    if (ind1 < 0 || ind2 < 0) // Check if either ot them is zero or not
    {
        return 0;
    }
    if (s1[ind1] == s2[ind2]) // If char matches
        return 1 + rec(s1, s2, ind1 - 1, ind2 - 1);
    return 0 + max(rec(s1, s2, ind1 - 1, ind2), rec(s1, s2, ind1, ind2 - 1));
}

int mem(string s1, string s2, int ind1, int ind2, vector<vector<int>> &dp)
{
    if (ind1 < 0 || ind2 < 0) // Check if either ot them is zero or not
    {
        return 0;
    }

    if (dp[ind1][ind2] != -1)
    {
        return dp[ind1][ind2];
    }

    if (s1[ind1] == s2[ind2]) // If char matches
        return dp[ind1][ind2] = 1 + mem(s1, s2, ind1 - 1, ind2 - 1, dp);
    return dp[ind1][ind2] = 0 + max(mem(s1, s2, ind1 - 1, ind2, dp), mem(s1, s2, ind1, ind2 - 1, dp));
}

int mem_shifted(string s1, string s2, int ind1, int ind2, vector<vector<int>> &dp)
{
    if (ind1 == 0 || ind2 == 0)
    {
        return 0;
    }

    if (dp[ind1][ind2] != -1)
    {
        return dp[ind1][ind2];
    }

    if (s1[ind1 - 1] == s2[ind2 - 1])
        return dp[ind1][ind2] = 1 + mem_shifted(s1, s2, ind1 - 1, ind2 - 1, dp);
    return dp[ind1][ind2] = 0 + max(mem_shifted(s1, s2, ind1 - 1, ind2, dp), mem_shifted(s1, s2, ind1, ind2 - 1, dp));
}

int tab(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

int sopt(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    for (int j = 0; j <= m; j++)
    {
        curr[j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                curr[j] = 1 + prev[j - 1];
            else
                curr[j] = 0 + max(prev[j], curr[j - 1]);
        }
        prev = curr;
    }
    return prev[m];
}
int main()
{
    string s1 = "acd", s2 = "ced";
    int lcs = 0, n = s1.size(), m = s2.size();
    lcs = rec(s1, s2, n - 1, m - 1);
    cout << lcs << endl;

    vector<vector<int>> dp(n, vector<int>(m, -1));
    lcs = mem(s1, s2, n - 1, m - 1, dp);
    cout << lcs << endl;

    vector<vector<int>> dp1(n + 1, vector<int>(m + 1, -1));
    lcs = mem_shifted(s1, s2, n, m, dp1);
    cout << lcs << endl;

    lcs = tab(s1, s2);
    cout << lcs << endl;

    lcs = sopt(s1, s2);
    cout << lcs << endl;
    return 0;
}
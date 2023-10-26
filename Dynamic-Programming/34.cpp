// Wild card matching
/*We are given two strings ‘S1’ and ‘S2’. String S1 can have the following two special characters:
‘?’ can be matched to a single character of S2.
‘*’ can be matched to any sequence of characters of S2. (sequence can be of length zero or more).
We need to check whether strings S1 and S2 match or not.*/
#include <bits/stdc++.h>
using namespace std;

bool rec(int i, int j, string &s1, string &s2)
{
    if (i < 0 && j < 0)
        return true;
    if (i < 0 && j >= 0)
        return false;
    if (i >= 0 && j < 0)
    {
        for (int k = 0; k <= i; k++)
        {
            if (s1[k] != '*')
                return false;
        }
    }

    if (s1[i] == s2[j] || s1[i] == '?')
        return rec(i - 1, j - 1, s1, s2);
    if (s1[i] == '*')
        return rec(i - 1, j, s1, s2) || rec(i, j - 1, s1, s2);
    return false;
}

bool mem(int i, int j, string &s1, string &s2, vector<vector<bool>> &dp)
{
    if (i < 0 && j < 0)
        return true;
    if (i < 0 && j >= 0)
        return false;
    if (i >= 0 && j < 0)
    {
        for (int k = 0; k <= i; k++)
        {
            if (s1[k] != '*')
                return false;
        }
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j] || s1[i] == '?')
        return dp[i][j] = rec(i - 1, j - 1, s1, s2);
    if (s1[i] == '*')
        return dp[i][j] = rec(i - 1, j, s1, s2) || rec(i, j - 1, s1, s2);
    return dp[i][j] = false;
}

bool isAllStars(string &s1, int i)
{
    for (int j = 1; j <= i; j++)
    {
        if (s1[j - 1] != '*')
            return false;
    }
    return true;
}
int tab(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, 0));
    dp[0][0] = true;
    for (int j = 1; j <= m; j++)
    {
        dp[0][j] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = isAllStars(s1, i);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (s1[i - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
            else
                dp[i][j] = false;
        }
    }
    return dp[n][m];
}

int spot(string &s1, string &s2)
{
    int n = s1.size(), m = s2.size();
    vector<bool> curr(m + 1, 0), prev(m + 1, 0);
    prev[0] = true;
    for (int j = 1; j <= m; j++)
    {
        curr[j] = false;
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     curr[0] = isAllStars(s1, i);
    // }

    for (int i = 1; i <= n; i++)
    {
        curr[0] = isAllStars(s1, i);
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
            {
                curr[j] = prev[j - 1];
            }
            else
            {
                if (s1[i - 1] == '*')
                    curr[j] = prev[j] || curr[j - 1];
                else
                    curr[j] = false;
            }
        }
        prev = curr;
    }
    return prev[m];
}
int main()
{
    string s1 = "ab*cd", s2 = "abdefcd";
    // string s1 = "ab?d", s2 = "abcc";
    int n = s1.size(), m = s2.size();
    bool ans = 0;
    ans = rec(n - 1, m - 1, s1, s2);
    cout << ans << endl;

    vector<vector<bool>> dp(n, vector<bool>(m, -1));
    ans = mem(n - 1, m - 1, s1, s2, dp);
    cout << ans << endl;

    ans = tab(s1, s2);
    cout << ans << endl;

    ans = spot(s1, s2);
    cout << ans << endl;

    if (ans)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}
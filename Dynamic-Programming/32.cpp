// Distinct subsequence : No of times s2 present in s1 an subsequence
#include <bits/stdc++.h>
using namespace std;
int rec(int i, int j, string s1, string s2)
{
    // j < 0 i.e string is matched completely
    if (j < 0)
        return 1;
    // i < 0 && j!<0 :. string 1 finishes but s2 remain :. 0
    if (i < 0)
        return 0;
    if (s1[i] == s2[j])
    {
        // First one is by selecting from s1 the curr char in s2 , 2nd one is by not selecting from s1 the curr char from s1
        return rec(i - 1, j - 1, s1, s2) + rec(i - 1, j, s1, s2);
    }
    else
    {
        return rec(i - 1, j, s1, s2);
    }
}

int mem(int i, int j, string s1, string s2, vector<vector<int>> &dp)
{
    if (j < 0)
        return 1;
    if (i < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] == s2[j])
    {
        return dp[i][j] = rec(i - 1, j - 1, s1, s2) + rec(i - 1, j, s1, s2);
    }
    else
    {
        return dp[i][j] = rec(i - 1, j, s1, s2);
    }
}

int tab(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    // since if i==0 j doesnt matter :. dp[0][0]=1 so j=1
    for (int j = 1; j <= m; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][m];
}

int spot(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    vector<int> prev(m + 1, 0), curr(m + 1, 0);
    prev[0] = 1, curr[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                curr[j] = prev[j - 1] + prev[j];
            }
            else
            {
                curr[j] = prev[j];
            }
        }
        prev = curr;
    }
    return prev[m];
}

int spot1(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    vector<int> prev(m + 1, 0);
    prev[0] = 1;
    // since if i==0 j doesnt matter :. dp[0][0]=1 so j=1
    for (int j = 1; j <= m; j++)
    {
        prev[j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                prev[j] = prev[j - 1] + prev[j];
            }
            else
            {
                prev[j] = prev[j];
            }
        }
    }
    return prev[m];
}
int main()
{
    string s1 = "babgbag", s2 = "bag";
    int n = s1.size(), m = s2.size();
    cout << rec(n - 1, m - 1, s1, s2) << endl;

    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << mem(n - 1, m - 1, s1, s2, dp) << endl;

    cout << tab(s1, s2) << endl;

    cout << spot(s1, s2) << endl;

    cout << spot1(s1, s2) << endl;
    return 0;
}
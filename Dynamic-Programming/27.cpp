// Longest Common Substring
#include <bits/stdc++.h>
using namespace std;
int tab(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    for (int j = 0; j <= m; j++)
        dp[0][j] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}
int sOpt(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    vector<int> curr(m + 1, 0), prev(m + 1, 0);
    for (int i = 0; i <= n; i++)
        prev[0] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
                ans = max(ans, curr[j]);
            }
            else
            {
                curr[j] = 0;
            }
        }
        prev = curr;
    }
    return ans;
}
int main()
{
    string s1 = "abcjklp", s2 = "acjkp";
    cout << tab(s1, s2) << endl;
    cout << sOpt(s1, s2) << endl;
    return 0;
}
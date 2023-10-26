// Min no of insertion and deletion to convert string 1 to strig 2
#include <bits/stdc++.h>
using namespace std;
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
int main()
{
    string s1 = "abcd";
    string s2 = "anc";
    int n = s1.size(), m = s2.size();
    int len_lcs = tab(s1, s2);
    int operations = n + m - 2 * len_lcs;
    cout << operations << endl;
    return 0;
}
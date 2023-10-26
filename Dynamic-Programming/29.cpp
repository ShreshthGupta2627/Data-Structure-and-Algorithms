// Minimum insertions to make string palindrome
#include <bits/stdc++.h>
using namespace std;
int tab(string s1, string s2)
{
    int n = s1.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = 0 + max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    // n-len( longest palindromic substring )
    return n - dp[n][n];
}
int main()
{
    string s1 = "bbabcbcab";
    string s2 = s1;
    reverse(s2.begin(), s2.end());
    cout << tab(s1, s2) << endl;
    return 0;
}
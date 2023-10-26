// Edit distance
/* We are given two strings S1 and S2.We need to convert S1 to S2.The following three operations are allowed :
Deletion of a character.Replacement of a character with another one.Insertion of a character.We have to return the minimum number of operations required to convert S1 to S2 as our answer */

#include <bits/stdc++.h>
using namespace std;
int rec(int i, int j, string s1, string s2)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;
    if (s1[i] == s2[j])
        return 0 + rec(i - 1, j - 1, s1, s2);
    int insert = 1 + rec(i, j - 1, s1, s2);
    int delet = 1 + rec(i - 1, j, s1, s2);
    int replace = 1 + rec(i - 1, j - 1, s1, s2);
    return min(min(insert, delet), replace);
}

int mem(int i, int j, string s1, string s2, vector<vector<int>> &dp)
{
    if (i < 0)
        return j + 1;
    if (j < 0)
        return i + 1;
    if (dp[i][j] != -1)
        return dp[i][j];

    if (s1[i] == s2[j])
        return dp[i][j] = 0 + rec(i - 1, j - 1, s1, s2);
    int insert = 1 + rec(i, j - 1, s1, s2);
    int delet = 1 + rec(i - 1, j, s1, s2);
    int replace = 1 + rec(i - 1, j - 1, s1, s2);
    return dp[i][j] = min(min(insert, delet), replace);
}
int tab(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // i+1  -> i bcz we move our indexing so i --> i-1 && j --> j-1
    for (int i = 0; i <= n; i++)
        dp[i][0] = i;
    for (int j = 1; j <= m; j++)
        dp[0][j] = j;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 0 + dp[i - 1][j - 1];
            else
            {
                int insert = 1 + dp[i][j - 1];
                int delet = 1 + dp[i - 1][j];
                int replace = 1 + dp[i - 1][j - 1];
                dp[i][j] = min(min(insert, delet), replace);
            }
        }
    }
    return dp[n][m];
}

int sopt(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    vector<int> curr(m + 1, 0), prev(m + 1, 0);
    // i+1  -> i bcz we move our indexing so i --> i-1 && j --> j-1

    // for (int i = 0; i <= n; i++)
    //     curr[0] = i;

    // We have to set curr[0]=i each time :. see line 81

    for (int j = 1; j <= m; j++)
        prev[j] = j;

    for (int i = 1; i <= n; i++)
    {
        curr[0] = i;
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                curr[j] = 0 + prev[j - 1];
            else
            {
                int insert = 1 + curr[j - 1];
                int delet = 1 + prev[j];
                int replace = 1 + prev[j - 1];
                curr[j] = min(min(insert, delet), replace);
            }
        }
        prev = curr;
    }
    return prev[m];
}

int main()
{
    string s1 = "horse", s2 = "ros";
    int n = s1.size(), m = s2.size();
    int ans = rec(n - 1, m - 1, s1, s2);
    cout << ans << endl;

    vector<vector<int>> dp(n, vector<int>(m, -1));
    ans = mem(n - 1, m - 1, s1, s2, dp);
    cout << ans << endl;

    cout << tab(s1, s2) << endl;

    cout << sopt(s1, s2) << endl;
    return 0;
}
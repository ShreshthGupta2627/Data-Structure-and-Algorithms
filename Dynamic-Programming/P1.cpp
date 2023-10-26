// Finding palindromic substring
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int idx1 = 0, idx2 = 0;

        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
            idx1 = i, idx2 = i;
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                dp[i][i + 1] = 1;
                idx1 = i;
                idx2 = i + 1;
            }
        }

        for (int len = 2; len < n; len++)
        {
            for (int i = 0; i < n - len; i++)
            {
                int j = i + len;

                if (s[i] == s[j] && dp[i + 1][j - 1] == 1)
                {
                    dp[i][j] = 1;
                    idx1 = i, idx2 = j;
                }
            }
        }
        if (s.length() == 1)
        {
            return s;
        }
        return s.substr(idx1, idx2);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    return 0;
}
// Longest String Chain

/*We are given an array of strings (sat words[ ]), and we need to return the longest string chain. This longest string chain is defined as:
1. A subsequence of words[ ] of the string.
2. Every element of this subsequence ( a string) except the first one can be formed by inserting a single character into the previous element.
3. The first element of this subsequence can be any string from the words[ ] array.*/

#include <bits/stdc++.h>
using namespace std;
bool cmp(string &s1, string &s2)
{
    return s1.size() < s2.size();
}
bool isPossible(string &s1, string &s2)
{
    if (s1.size() != s2.size() + 1)
    {
        // Not possible we are adding single char ata a time
        return 0;
    }
    int i = 0, j = 0;
    while (i < s1.size())
    {
        if (j < s2.size() && s1[i] == s2[j])
        {
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    if (i == s1.size() && j == s2.size())
    {
        return 1;
    }
    return 0;
}
int Lsc(vector<string> &a)
{
    int n = a.size();
    vector<int> dp(n, 1);
    for (int ind = 0; ind < n; ind++)
    {
        for (int prev = 0; prev < ind; prev++)
        {
            if (isPossible(a[ind], a[prev]) && dp[ind] < 1 + dp[prev])
            {
                dp[ind] = dp[prev] + 1;
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}
int main()
{
    vector<string> s = {"x", "xx", "y", "xyx"};
    sort(s.begin(), s.end(), cmp);
    cout << Lsc(s) << endl;
    return 0;
}
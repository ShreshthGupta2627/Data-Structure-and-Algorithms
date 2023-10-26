// count the number of longest increasing subsequences
// Given an array, ‘Arr’ of length ‘n’, count the number of longest increasing subsequences (LIS).

#include <bits/stdc++.h>
using namespace std;
int cntLis(vector<int> &a)
{
    int n = a.size();
    // The element itself will be counted and is part of lis :. 1
    vector<int> dp(n, 1), cnt(n, 1);
    for (int ind = 1; ind < n; ind++)
    {
        for (int prev = 0; prev < ind; prev++)
        {
            if (a[prev] < a[ind] && dp[ind] < dp[prev] + 1)
            {
                dp[ind] = 1 + dp[prev];
                // Just inheriting from previous
                cnt[ind] = cnt[prev];
            }
            else if (a[prev] < a[ind] && dp[ind] == dp[prev] + 1)
            {
                // The no of times previous can form , the number of diff ways we can add to get that length
                cnt[ind] += cnt[prev];
            }
        }
    }
    int maxx = *max_element(dp.begin(), dp.end()), ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxx)
        {
            ans += cnt[i];
        }
    }
    return ans;
}
int main()
{
    vector<int> v = {1, 3, 5, 4, 7};
    cout << cntLis(v) << endl;
    return 0;
}
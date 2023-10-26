// Given an array with distinct elements, we need to print its longest divisible subset. We can print any answer.
#include <bits/stdc++.h>
using namespace std;

int Longest_divisible_subset(vector<int> &a)
{
    int n = a.size();
    sort(a.begin(), a.end());
    // 1 is there ncz everyone itself must be in LIS
    vector<int> dp(n, 1), backtrack(n, 0);
    for (int i = 0; i < n; i++)
    {
        backtrack[i] = i;
    }
    for (int ind = 0; ind < n; ind++)
    {
        for (int prev = 0; prev < ind; prev++)
        {
            if ((a[ind] % a[prev] == 0) && (dp[ind] < 1 + dp[prev]))
            {
                dp[ind] = max(dp[ind], 1 + dp[prev]);
                backtrack[ind] = prev;
            }
        }
    }
    int len_lis = *max_element(dp.begin(), dp.end());
    int Last_Ind = max_element(dp.begin(), dp.end()) - dp.begin();
    vector<int> lis;
    lis.push_back(a[Last_Ind]);
    while (backtrack[Last_Ind] != Last_Ind)
    {
        Last_Ind = backtrack[Last_Ind];
        lis.push_back(a[Last_Ind]);
    }
    reverse(lis.begin(), lis.end());
    for (auto &it : lis)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}

int main()
{
    vector<int> a = {1, 16, 4, 7, 8};
    Longest_divisible_subset(a);
    return 0;
}
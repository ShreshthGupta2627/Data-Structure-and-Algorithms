// Longest Bitonic Subsequence
/*A bitonic subsequence is a subsequence of an array in which the elements can be any of these three:
1. First, increase till a point and then decrease.
2. Goes on increasing (Longest increasing subsequence)
3. Goes on decreasing (Longest decreasing subsequence)*/

#include <bits/stdc++.h>
using namespace std;
int Lis(vector<int> &a)
{
    int n = a.size();
    vector<int> dp_front(n, 1), dp_back(n, 1);
    for (int ind = 0; ind < n; ind++)
    {
        for (int prev = 0; prev < ind; prev++)
        {
            if (a[ind] > a[prev] && dp_front[ind] < dp_front[prev] + 1)
            {
                dp_front[ind] = dp_front[prev] + 1;
            }
        }
    }
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev = n - 1; prev > ind; prev--)
        {
            if (a[ind] > a[prev] && dp_back[ind] < dp_back[prev] + 1)
            {
                dp_back[ind] = dp_back[prev] + 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        dp_front[i] = dp_front[i] + dp_back[i];
    }
    return (*max_element(dp_front.begin(), dp_front.end()) - 1);
}
int main()
{
    vector<int> v = {1, 11, 2, 10, 4, 5, 2, 1};
    cout << Lis(v) << endl;
    return 0;
}
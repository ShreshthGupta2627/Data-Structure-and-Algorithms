/*There is given an integer array A of size N denoting the heights of N trees.
Lumberjack Ojas needs to chop down B metres of wood. It is an easy job for him since he has a nifty new woodcutting machine that can take down forests like wildfire. However, Ojas is only allowed to cut a single row of trees.
Ojas's machine works as follows: Ojas sets a height parameter H (in metres), and the machine raises a giant sawblade to that height and cuts off all tree parts higher than H (of course, trees not higher than H meters remain intact). Ojas then takes the parts that were cut off. For example, if the tree row contains trees with heights of 20, 15, 10, and 17 metres, and Ojas raises his sawblade to 15 metres, the remaining tree heights after cutting will be 15, 15, 10, and 15 metres, respectively, while Ojas will take 5 metres off the first tree and 2 metres off the fourth tree (7 metres of wood in total).
Ojas is ecologically minded, so he doesn't want to cut off more wood than necessary. That's why he wants to set his sawblade as high as possible. Help Ojas find the maximum integer height of the sawblade that still allows him to cut off at least B metres of wood.

NOTE:
The sum of all heights will exceed B, thus Ojas will always be able to obtain the required amount of wood.*/
#include <bits/stdc++.h>
#define int long long
using namespace std;
int solve(vector<int> &A, int B)
{
    int s = 0;
    int n = A.size();
    int e = *max_element(A.begin(), A.end());

    while (e >= s)
    {
        int sub = 0;
        int mid = s + ((e - s) >> 1);
        for (int i = 0; i < n; i++)
        {
            if (A[i] > mid)
            {
                sub = sub + A[i] - mid;
            }
        }
        if (sub >= B)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return e;
}
int32_t main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &it : v)
    {
        cin >> it;
    }
    int b;
    cin >> b;
    cout << solve(v, b) << endl;
    return 0;
}
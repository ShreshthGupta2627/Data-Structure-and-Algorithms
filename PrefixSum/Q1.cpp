/*

You have a farm on the i th day of Q days you get one harvest on field [Li, Ri], after n days the farmer want to
know how many field has >= k harvest on them for all k in range [0,Q]

*/
#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    int n;
    cin >> n;

    vector<int> farm(n, 0);
    int q;
    cin >> q;
    vector<int> lenCnt(q + 1, 0);

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        farm[l]++;
        if (r + 1 < n)
        {
            farm[r + 1]--;
        }
    }

    for (int i = 1; i < n; i++)
    {
        farm[i] += farm[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        if (farm[i] <= q)
            lenCnt[farm[i]]++;
    }

    for (int i = q - 1; i >= 0; i--)
    {
        lenCnt[i] += lenCnt[i + 1];
    }
    for (int i = 1; i <= q; i++)
    {
        cout << i << " " << lenCnt[i] << endl;
    }

    return 0;
}
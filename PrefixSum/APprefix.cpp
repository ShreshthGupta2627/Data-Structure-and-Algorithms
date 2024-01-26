/*

Given an array with all 0's and we are given q updates with a d l r as first term, common difference and range
respectively print final error

*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    int n;
    cin >> n;
    vector<int> cnst(n, 0), var(n, 0);

    int q;
    cin >> q;
    while (q--)
    {
        int a, d, l, r;
        cin >> a >> d >> l >> r;

        cnst[l] += a - d * l;
        if (r + 1 < n)
        {
            cnst[r + 1] -= (a - d * l);
        }

        var[l] += d;
        if (r + 1 < n)
        {
            var[r + 1] -= d;
        }
    }

    for (int i = 1; i < n; i++)
    {
        cnst[i] += cnst[i - 1];
        var[i] += var[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        cout << cnst[i] + i * var[i] << " ";
    }
    cout << endl;
    return 0;
}
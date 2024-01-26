#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{

    int n;
    cin >> n;
    vector<int> v(n), v1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v1[i] = -v[i];
    }

    sort(v.begin(), v.end());
    sort(v1.begin(), v1.end());

    int k;
    cin >> k;
    while (k--)
    {
        int l, r;
        cin >> l >> r;

        int idxl = lower_bound(v.begin(), v.end(), l) - v.begin();
        int idxu = lower_bound(v1.begin(), v1.end(), -r) - v1.begin();

        idxu = n - 1 - (idxu);

        cout << idxu - idxl + 1 << " ";
    }
    return 0;
}
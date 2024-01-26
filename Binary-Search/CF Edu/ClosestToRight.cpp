#include <bits/stdc++.h>
#define int long long
using namespace std;

int findOne(int low, int high, int key, vector<int> &v)
{
    int maxIndex = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (v[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            maxIndex = mid;
            high = mid - 1;
        }
    }
    return (maxIndex < 0) ? v.size(z) + 1 : maxIndex + 1;
}

int32_t main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (auto &it : v)
    {
        cin >> it;
    }

    while (k--)
    {
        int a;
        cin >> a;
        cout << findOne(0, n - 1, a, v) << endl;
    }
    return 0;
}
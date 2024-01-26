// Implement a binary search algorithm.

#include <bits/stdc++.h>
#define int long long
using namespace std;

bool bs(int low, int high, int key, vector<int> &v)
{
    while (low <= high)
    {
        int mid = (high - low) / 2 + low;

        if (v[mid] == key)
        {
            return true;
        }
        else if (v[mid] > key)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return false;
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

        bool f = bs(0, n - 1, a, v);
        if (f)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
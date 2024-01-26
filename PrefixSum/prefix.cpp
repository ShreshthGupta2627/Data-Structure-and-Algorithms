#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> pref;

    pref.push_back(v[0]);
    for (int i = 1; i < v.size(); i++)
    {
        pref.push_back(pref.back() + v[i]);
    }

    for (auto &it : pref)
    {
        cout << it << " ";
    }

    int q = 1;
    while (q--)
    {
        int l = 1, r = 5;
        int ans = pref[r];
        if (l)
        {
            ans -= pref[l - 1];
        }
        cout << ans << endl;
    }
    return 0;
}
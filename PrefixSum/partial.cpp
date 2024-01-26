/*

Given N size array, Support Q update
    + l r x =>  for(i = l; i < r; i++)
                {
                    v[i] += x;
                }

    After that print final array

*/

#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    vector<int> partial(v.size(), 0);
    partial.push_back(v[0]);
    for (int i = 1; i < v.size(); i++)
    {
        partial.push_back(partial.back() + v[i]);
    }

    int q;
    cin >> q;
    while (q--)
    {
        int l, r, x;
        cin >> l >> r >> x;
        l--, r--;
        partial[l] += x;
        if (r + 1 < v.size())
        {
            partial[r + 1] -= x;
        }
    }

    for (int i = 1; i < partial.size(); i++)
    {
        partial[i] += partial[i - 1];
    }

    for (int i = 0; i < v.size(); i++)
    {
        v[i] += partial[i];
    }

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    return 0;
}
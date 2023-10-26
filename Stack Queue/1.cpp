#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> nse(n, n), lse(n, -1);
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && v[i] < v[s.top()])
        {
            s.pop();
        }
        if (s.empty())
        {
            nse[i] = n;
        }
        else
        {
            nse[i] = s.top();
        }
        s.push(i);
    }
    while (!s.empty())
    {
        s.pop();
    }
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && v[i] < v[s.top()])
        {
            s.pop();
        }
        if (s.empty())
        {
            lse[i] = -1;
        }
        else
        {
            lse[i] = s.top();
        }
        s.push(i);
    }
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, v[i] * (nse[i] - lse[i] - 1));
    }
    cout << ans << endl;
    return 0;
}
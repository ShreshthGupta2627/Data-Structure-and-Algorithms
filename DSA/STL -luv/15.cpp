// Next greater element
#include <bits/stdc++.h>
using namespace std;
vector<int> NGE(vector<int> v)
{
    vector<int> nge(v.size());
    stack<int> s;
    for (int i = 0; i < v.size(); i++)
    {
        while (!s.empty() && v[i] > v[s.top()])
        {
            nge[s.top()] == i;
        }
        s.push(i);
    }
    while (!s.empty())
    {
        nge[s.top()] = -1;
        s.pop();
    }
    return nge;
}
int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &i : v)
    {
        cin >> i;
    }
    vector<int> nge = NGE(v);
    for (auto &i : nge)
    {
        cout << i << " ";
    }
    return 0;
}
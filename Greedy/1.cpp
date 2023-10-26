// Fractional knapsack

/*The weight of N items and their corresponding values are given. We have to put these items in a knapsack of weight W such that the total value obtained is maximized.
Note: We can either take the item as a whole or break it into smaller units.

Example:
Input: N = 3, W = 50, values[] = {100,60,120}, weight[] = {20,10,30}.
Output: 240.00
Explanation: The first and second items  are taken as a whole  while only 20 units of the third item is taken. Total value = 100 + 60 + 80 = 240.00*/
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<float, pair<int, int>> a, pair<float, pair<int, int>> b)
{
    return b.first < a.first;
}
int solve(vector<int> &i, vector<int> &w, int s)
{
    vector<pair<float, pair<int, int>>> v;
    for (int j = 0; j < i.size(); j++)
    {
        v.push_back({(float)i[j] / w[j], {i[j], w[j]}});
    }
    sort(v.begin(), v.end(), cmp);
    int j = 0;
    float ans = 0;
    while (s >= w[j] && j < i.size())
    {
        ans += v[j].second.first;
        s -= v[j].second.second;
        j++;
    }
    if (s > 0 && j < i.size())
        ans += (((float)s / w[j]) * i[j]);
    return ans;
}
int main()
{
    vector<int> i = {75250, 50074, 43659, 8931, 11273, 27545, 50879, 77924};
    vector<int> w = {112960, 114515, 81825, 93424, 54316, 35533, 73383, 160252};
    // vector<int> i = {60, 100, 120};
    // vector<int> w = {10, 20, 30};
    int s = 50;
    cout << solve(i, w, 50) << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int n = 2000;
int prefix_sum[n][n];
int main()
{
    vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}};
    int m = v.size();
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + v[i - 1][j - 1];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            cout << prefix_sum[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
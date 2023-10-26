#include <bits/stdc++.h>
using namespace std;

void precompute()
{
    int maxn = 10;
    vector<vector<int>> C(maxn + 1, vector<int>(maxn + 1, 1e9));
    C[0][0] = 1;

    for (int n = 1; n <= maxn; n++)
    {
        C[n][0] = 1, C[n][n] = 1;
        for (int k = 1; k < n; k++)
        {
            C[n][k] = C[n - 1][k - 1] + C[n - 1][k];
        }
    }
    // C[n][k] => nCk
}

int main()
{
    precompute();
    return 0;
}
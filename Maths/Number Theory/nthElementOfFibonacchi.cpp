#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int MOD = 1e9 + 7;

int ADD(int a, int b)
{
    return (a % MOD + b % MOD) % MOD;
}
int MUL(int a, int b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}

vector<vector<int>> v, I;

void mm(int dim, vector<vector<int>> &a, vector<vector<int>> &b)
{
    vector<vector<int>> res(dim, vector<int>(dim, 0));

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            for (int k = 0; k < dim; k++)
            {
                int temp = MUL(a[i][k], b[k][j]);
                res[i][j] = ADD(res[i][j], temp);
            }
        }
    }

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            a[i][j] = res[i][j];
        }
    }
}

void me(int dim, int n)
{
    while (n)
    {
        if (n & 1)
        {
            mm(dim, I, v);
        }
        n /= 2;
        mm(dim, v, v);
    }
}

void solve()
{
    // Transition matrix will be | 0   1 |
    //                           | 1   1 |
    // F1 = 0, F2 = 1

    vector<int> ans = {0, 1};
    v = {{0, 1}, {1, 1}};
    I = {{1, 0}, {0, 1}};

    int n;
    cin >> n;

    if (n < 2)
    {
        cout << ans[n] << endl;
    }
    else
    {
        me(2, n);
        int fn = ((ans[0] * I[0][0]) % MOD + (ans[1] * I[1][0]) % MOD) % MOD;
        cout << fn << endl;
    }
}

int32_t main()
{
    solve();
    return 0;
}
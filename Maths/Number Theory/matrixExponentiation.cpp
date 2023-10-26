#include <bits/stdc++.h>
using namespace std;

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
                res[i][j] += a[i][k] * b[k][j];
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

    for (auto &it : I)
    {
        for (auto &it1 : it)
        {
            cout << it1 << " ";
        }
        cout << endl;
    }
}

int main()
{
    int dim, n;
    cin >> dim >> n;

    v.resize(dim, vector<int>(dim, 0));
    I.resize(dim, vector<int>(dim, 0));

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            cin >> v[i][j];
        }
    }

    for (int j = 0; j < dim; j++)
    {
        I[j][j] = 1;
    }

    me(dim, n);

    return 0;
}
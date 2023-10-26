#include <bits/stdc++.h>
using namespace std;

int ncr(int n, int r)
{
    double res = 1.0;
    for (int i = 1; i <= r; i++)
    {
        res *= ((n - r + i) / i);
    }
    return res + 0.01;
}

int main()
{

    cout << ncr(6, 2) << endl;
    return 0;
}
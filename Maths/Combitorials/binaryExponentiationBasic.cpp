#include <bits/stdc++.h>
using namespace std;

int ncr(int n, int r)
{
    int res = 1;
    for (int i = n - r + 1; i <= n; i++)
    {
        res *= i;
    }
    for (int i = 1; i <= r; i++)
    {
        res /= i;
    }
    return res;
}

int main()
{

    cout << ncr(6, 2) << endl;
    return 0;
}
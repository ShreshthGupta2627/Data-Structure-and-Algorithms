#include <bits/stdc++.h>
using namespace std;

void bem(int a, int n, int p)
{
    int res = 1;

    while (n)
    {
        if (n & 1)
        {
            res = (res * a) % p;
        }
        n /= 2;
        a = (a * a) % p;
    }

    cout << res << endl;
}

int main()
{
    bem(5, 3, 1e9 + 7);
    return 0;
}
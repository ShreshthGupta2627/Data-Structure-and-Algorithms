#include <bits/stdc++.h>
using namespace std;

void be(int a, int n)
{
    int res = 1;

    while (n)
    {
        if (n & 1)
        {
            res *= a;
        }
        n /= 2;
        a *= a;
    }

    cout << res << endl;
}

int main()
{
    be(5, 3);
    return 0;
}
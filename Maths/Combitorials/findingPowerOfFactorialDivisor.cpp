#include <bits/stdc++.h>
using namespace std;
int fact_pow(int n, int k)
{
    int res = 0;
    while (n)
    {
        n /= k;
        res += n;
    }
    return res;
}
int main()
{
    cout << fact_pow(10, 5) << endl;
    return 0;
}
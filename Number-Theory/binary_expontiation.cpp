#include <bits/stdc++.h>
using namespace std;
int solve_naive(int base, int pow)
{
    int res = 1;
    for (int i = 0; i < pow; i++)
    {
        res *= base;
    }
    return res;
}
int solve(int base, int pow)
{
    // For calculating a^n in O(logn) time
    // for a ^ n where n is odd made it as a * (a ^ (n-1)) ,  we just need to square the base every time and reduce power to half
    int res = 1;
    while (pow)
    {
        if (pow & 1)
        {
            res *= base;
            pow--;
        }
        else
        {
            base *= base;
            pow /= 2;
        }
    }
    return res;
    // TC O(log(pow)) base 2;
}
int solve_mod(int base, int pow, int mod)
{
    int res = 1;
    while (pow)
    {
        if (pow & 1)
        {
            res = (res * base) % mod;
            pow--;
        }
        else
        {
            base = (base * base) % mod;
            pow /= 2;
        }
    }
    return res;
}
int main()
{
    cout << solve_naive(625, 3) << endl;
    cout << solve(625, 3) << endl;
    cout << solve_mod(625, 3, 100);
    return 0;
}
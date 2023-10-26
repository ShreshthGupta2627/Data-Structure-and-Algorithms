// Theorum is used to determine wheather a number is prome or not
#include <bits/stdc++.h>
using namespace std;
bool solve_naive(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
    // TC : O(n)
}
bool solve_improved(int n)
{
    // divisor occour in pair (a,b) such that n = a*b and if one is less the sqrt(a*b) then other is greater then it :. we can reduvce loop till sqrt(n) this can be easily proved by taking a * b = sqrt(n)* sqrt(n) consider b once less and once greater and see position of a
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
    // TC :O(sqrt(n))
}
int main()
{
    int n = 53;
    cout << solve_naive(n) << endl;
    cout << solve_improved(n) << endl;
    return 0;
}
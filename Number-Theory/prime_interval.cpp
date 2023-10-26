// Primes between l to r
#include <bits/stdc++.h>
using namespace std;
bool is_prime(int n)
{
    if (n == 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
void solve(int L, int R)
{
    vector<int> primes;
    // print all the prime number between L and R
    for (int i = L; i <= R; i++)
    {
        if (is_prime(i))
            cout << i << " ";
    }
    cout << endl;
}
int main()
{
    solve(1, 100);
    return 0;
}
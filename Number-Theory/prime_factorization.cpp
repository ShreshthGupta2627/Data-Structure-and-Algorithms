#include <bits/stdc++.h>
using namespace std;
void solve_naive(int n)
{
    for (int i = 2; i <= n; i++)
    {
        int cnt = 0;
        while (n % i == 0)
        {
            cnt++;
            n /= i;
        }
        cout << i << " " << cnt << endl;
    }
    // TC : O(n)
}
void solve(int n)
{
    // If n is composite then there is atleast 1 prime number less than sqrt(n)
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                cnt++;
                n /= i;
            }
            cout << i << " " << cnt << endl;
        }
    }
    // but if n is prime it has no prime divisor before sqrt(n)
    if (n > 1)
        cout << n << " " << 1 << endl;
    // TC : O(sqrt(n))
}
int main()
{
    solve_naive(120);
    solve(120);
    return 0;
}
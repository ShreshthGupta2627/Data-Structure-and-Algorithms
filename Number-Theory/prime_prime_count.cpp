// A number x is called prime prime if number of primes between 1 to x (x inclusive) if it has prime count of prime numbers
#include <bits/stdc++.h>
using namespace std;
int a[1000000 + 1];
void sieve()
{
    int maxN = 1000000;
    for (int i = 0; i < maxN; i++)
    {
        a[i] = 1;
    }
    a[0] = a[1] = 0;
    for (int i = 2; i * i <= maxN; i++)
    {
        if (a[i] & 1)
        {
            for (int j = i * i; j <= maxN; j += i)
            {
                a[j] = 0;
            }
        }
    }
}
bool solve(int L, int R)
{
    sieve();
    int cnt = 0;
    for (int i = 0; i < R; i++)
    {
        if (a[i] & 1)
        {
            cnt++;
            if (a[cnt] & 1)
            {
                cout << i << " ";
            }
        }
    }
    cout << endl;
}
int main()
{
    solve(1, 100);
    return 0;
}
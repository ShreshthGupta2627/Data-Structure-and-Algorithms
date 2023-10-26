#include <bits/stdc++.h>
using namespace std;
int is_prime[90000001];
vector<int> primes;
bool solve()
{
    // Find the kth is_prime number between 1 to 5000000 this can be found with list of 90000000
    int maxN = 90000000;
    for (int i = 1; i <= maxN; i++)
    {
        is_prime[i] = false;
    }
    is_prime[0] = is_prime[1] = true;
    for (int i = 2; i * i <= maxN; i++)
    {
        if (!is_prime[i])
        {
            for (int j = i * i; j <= maxN; j += i)
            {
                is_prime[j] = true;
            }
        }
    }
    for (int i = 2; i * i <= maxN; i++)
    {
        if (!is_prime[i])
        {
            primes.push_back(i);
        }
    }
}
int main()
{
    int k = 9;
    solve();
    cout << primes[k - 1] << endl;
    return 0;
}
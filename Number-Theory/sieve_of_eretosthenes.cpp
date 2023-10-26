#include <bits/stdc++.h>
using namespace std;
int is_prime[1000001];
bool solve()
{
    // For given nearly 1e6 queries and we need to return wheather a number is prime or not
    // Use an array to store val form 1 to n and then start filling for prime fill 1 and fill all no divisible by it as 0 and proccede also while checking for no dividible by a we should start check form pow(a,2) since if not so it is factor of someting less then a and it was already been covered
    int maxN = 1000000;
    for (int i = 1; i <= maxN; i++)
    {
        is_prime[i] = 1;
    }
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i <= maxN; i++)
    {
        if (is_prime[i])
        {
            for (int j = i * i; j <= maxN; j += i)
            {
                is_prime[j] = 0;
            }
        }
    }
    // TC : O(n*ln(ln(n)))
}
int main()
{
    solve();
    cout << is_prime[53] << endl;
    return 0;
}
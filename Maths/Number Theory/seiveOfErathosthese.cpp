#include <bits/stdc++.h>
using namespace std;

vector<int> isPrime(1e6 + 1, 1);

void soe()
{
    int maxN = 1e6;
    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i * i <= maxN; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= maxN; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
}

int main()
{
    soe();
    cout << isPrime[4] << isPrime[3] << endl;
    return 0;
}
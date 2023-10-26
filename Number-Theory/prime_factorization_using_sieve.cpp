// Prime factorization in O(log(n))
#include <bits/stdc++.h>
using namespace std;
vector<int> a(1000001, -1);
void solve()
{
    int maxN = 1000000;
    for (int i = 2; i <= maxN; i++)
    {
        if (a[i] == -1)
        {
            for (int j = i; j <= maxN; j += i)
            {
                if (a[j] == -1)
                {
                    a[j] = i;
                }
            }
        }
    }
}
int main()
{
    solve();
    int n = 624;
    while (n)
    {
        cout << a[n] << " ";
        n /= a[n];
        if (n == 1)
            break;
    }
    return 0;
}
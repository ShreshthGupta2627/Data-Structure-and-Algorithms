#include <bits/stdc++.h>
using namespace std;

void pfs(int n)
{
    int maxN = 1e6;
    vector<int> pf(1e6 + 1);
    for (int i = 0; i <= maxN; i++)
    {
        pf[i] = i;
    }

    for (int i = 2; i * i <= 1e6; i++)
    {
        for (int j = i * i; j < maxN; j += i)
        {
            if (pf[j] == j)
            {
                pf[j] = i;
            }
        }
    }
 
    while (n != 1)
    {
        cout << pf[n] << " ";
        n /= pf[n];
    }
}

int main()
{
    pfs(38);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
map<int, int> pmf;
void pf(int N)
{
    for (int i = 2; i <= N; i++)
    {
        if (N % i == 0)
        {
            while (N % i == 0)
            {
                pmf[i]++;
                N /= i;
            }
        }
    }
    if (N > 1)
    {
        pmf[N]++;
    }

    for (auto &it : pmf)
    {
        cout << it.first << " ^ " << it.second << endl;
    }
}
int main()
{
    pf(12);
    // TC is O(sqrt(N))
    return 0;
}
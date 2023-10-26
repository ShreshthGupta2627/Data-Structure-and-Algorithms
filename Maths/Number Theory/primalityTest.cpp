#include <bits/stdc++.h>
using namespace std;
bool pt(int n)
{
    if (n == 1)
    {
        return false;
    }

    for (int i = 2; i * i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}
int main()

{
    // TC : O(sqrt(N))
    cout << pt(9) << endl;
    return 0;
}
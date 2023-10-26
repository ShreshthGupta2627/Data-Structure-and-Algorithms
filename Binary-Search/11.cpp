// split a number into two parts such that diff b/w sum of digit is either 1 or 0
#include <bits/stdc++.h>
#define int long long int
#define tc while (t--)
#define ret0 return 0;
using namespace std;
int dsum(int n)
{
    int digsum = 0;
    while (n)
    {
        digsum += (n % 10);
        n /= 10;
    }
    return digsum;
}
int binary_search(int low, int high, int n)
{
    int mid = (low + high) >> 1;
    if (abs(dsum(mid) - dsum(n - mid)) <= 1)
    {
        cout << mid << " " << n - mid << endl;
        return 0;
    }
    else if (dsum(mid) < dsum(n - mid))
    {
        binary_search(mid + 1, high, n);
    }
    else
    {
        binary_search(low, mid - 1, n);
    }
    return 0;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    tc
    {
        int n;
        cin >> n;
        binary_search(0, n, n);
    }
    ret0
}
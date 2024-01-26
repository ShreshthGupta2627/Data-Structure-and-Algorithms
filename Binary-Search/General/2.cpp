#include <bits/stdc++.h>
using namespace std;
double multiply(double number, int n)
{
    double ans = 1.0;
    for (int i = 0; i < n; i++)
    {
        ans *= number;
    }
    return ans;
}
double nth_root_of_m(int n, int m)
{
    // Nth root of a number M using binary search say n=3 and m=27 we need to find cube root of 27
    // We can use binary search to do that as bs can be applied to find anyting in an array if it is monotonus in nature
    // nth root of something > 1 will lie between 1 and n
    double low = 1;
    double high = n;
    double limit = 10e-6;
    while (high - low > limit)
    {
        double mid = (low + high) / 2.0;
        if (multiply(mid, n) < m)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    return low;

    // Time Complexity : n * (log(n * d) base 2)
    // Normal bs :logn base 2
    // But in this case we are taking decimal like if i set precision to 'd' decimal places then it will be : log(n*d) base 2
    // We are also running a loop each time to finding replacement of low and high which will also aads up to tc : n*(log(n*d) base 2)
}
int main()
{
    int n = 3, m = 25;
    cout << fixed << setprecision(6) << nth_root_of_m(n, m) << endl;
    return 0;
}
// Fibonacci series dynamic program
#include <bits/stdc++.h>
using namespace std;
int dpfib(int n, vector<int> &fib_arr)
{
    // Tc = O(n) , Sc=O(n)
    if (n <= 1)
    {
        return n;
    }
    if (fib_arr[n] != -1)
    {
        return fib_arr[n];
    }
    fib_arr[n] = dpfib(n - 1, fib_arr) + dpfib(n - 2, fib_arr);
    return fib_arr[n];
}
int tabfib(int n)
{
    // Tc = O(n) , Sc=O(n)
    int dpfib[n + 1];
    dpfib[0] = 0, dpfib[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dpfib[i] = dpfib[i - 1] + dpfib[i - 2];
    }
    return dpfib[n];
}
int optfib(int n)
{
    // Tc = O(n) , Sc=O(1)
    auto prev2 = 0, prev = 1, curr = 0;
    for (auto i = 2; i < n + 1; i++)
    {
        curr = prev2 + prev;
        prev2 = prev;
        prev = curr;
    }
    return curr;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> fib_arr(n + 1, -1);
    cout << dpfib(n, fib_arr) << endl;
    cout << optfib(n);
    return 0;
}

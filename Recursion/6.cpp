// Multiple recursion calls
#include <bits/stdc++.h>
using namespace std;

// Fibonacchi number
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

// Time complexity :- O(2^n) i.e exponential
int main()
{
    cout << fib(5);
    return 0;
}
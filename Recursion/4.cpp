// Parameterised and functional recursion
// Sum of n number using recursion
#include <bits/stdc++.h>
using namespace std;

// Parameterised way i.e. sum as parameter
void sum(int i, int summ)
{
    if (i < 1)
    {
        cout << summ << endl;
        return;
    }
    sum(i - 1, summ + i);
}

// Functional recurssive way
int sum1(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return sum1(n - 1) + n;
}
int main()
{
    int n = 5;
    sum(n, 0);
    cout << sum1(n);
    return 0;
}

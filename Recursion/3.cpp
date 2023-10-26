#include <bits/stdc++.h>
using namespace std;
void name(int x)
{
    if (x > 0)
    {
        cout << "SHRESHTH GUPTA" << endl;
        name(x - 1);
    }
}
void num(int i, int n)
{
    if (n >= i)
    {
        cout << n << endl;
        num(i, n - 1);
    }
    else
        return;
}
void num2(int i, int n)
{
    if (n < i)
    {
        return;
    }
    cout << i << " ";
    num2(i + 1, n);
}
void num1_backtrack(int i, int n)
{
    if (i < 1)
        return;
    num1_backtrack(i - 1, n);
    cout << i << " ";
}
void num2_backtrack(int i, int n)
{
    if (i > n)
        return;

    num2_backtrack(i + 1, n);
    cout << i << " ";
}
int main()
{
    num2_backtrack(1, 5);
    return 0;
}
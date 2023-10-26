// Infinite recursion :. We need some stopping condition
#include <bits/stdc++.h>
using namespace std;
void fun(int x)
{
    cout << x << " ";
    fun(x);
}
int main()
{
    fun(1);
    return 0;
}
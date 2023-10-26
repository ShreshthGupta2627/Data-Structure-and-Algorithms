// here is the stopping condition
#include <bits/stdc++.h>
using namespace std;
void fun(int x)
{
    cout << x << " ";
    if (x > 1) // base condn
        fun(x - 1);
}
int main()
{
    fun(10);
    return 0;
}
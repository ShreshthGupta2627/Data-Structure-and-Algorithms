#include <bits/stdc++.h>
using namespace std;
int path(int x)
{
    if (x == 0 || x == 1)
        return 1;
    else
        return path(x - 1) + path(x - 2);
    // The way to find all ways is to return 1 on base case and in the stair problem try to symbolise each stair with index and apply operation on that only i.e move 1 or 2 move from 1-->n = n-->1
}
int main()
{
    int n;
    cout << "Enter number of steps : ";
    cin >> n;
    cout << path(n);
    return 0;
}
// count the number of subsequence with sum=k
#include <bits/stdc++.h>
using namespace std;
// To count if satisfies return 1 in base case and if not return 0 in base case as base case is going to give result at end of recursive calls
int print(int indx, int s, int sum, vector<int> &v, int n)
{
    // if all +ve in list
    if (s > sum)
        return 0;
    if (indx == n)
    {
        // condn satisfied
        if (sum == s)
        {
            return 1;
        }
        // condn not satisfied
        return 0;
    }
    // take the particular index into the subsequence
    s += v[indx];
    int l = print(indx + 1, s, sum, v, n);
    s -= v[indx];
    // not take the particular index into the subsequence
    int r = print(indx + 1, s, sum, v, n);
    return l + r;
}
int main()
{
    vector<int> v = {1, 2, 1};
    int n = 3;
    int sumreq = 2;
    cout << print(0, 0, sumreq, v, n);
    return 0;
}
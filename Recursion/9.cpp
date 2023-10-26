// Print any subsequence with sum s
#include <bits/stdc++.h>
using namespace std;
// In recursion instead to check a condition use bool as using flag is not recommanded till you dont find the value return false and continue and if found return true and stop
bool print(int indx, vector<int> &ds, int s, int sum, vector<int> &v, int n)
{
    if (indx == n)
    {
        // condn satisfied
        if (sum == s)
        {
            for (auto &it : ds)
            {
                cout << it << " ";
            }
            cout << endl;
            return true;
        }
        // condn not satisfied
        return false;
    }
    // take the particular index into the subsequence
    ds.push_back(v[indx]);
    s += v[indx];
    if (print(indx + 1, ds, s, sum, v, n) == true)
        return true;
    s -= v[indx];
    ds.pop_back();
    // not take the particular index into the subsequence
    if (print(indx + 1, ds, s, sum, v, n) == true)
        return true;
    return false;
}
int main()
{
    vector<int> v = {1, 2, 1};
    int n = 3;
    vector<int> ds;
    int sumreq = 2;
    print(0, ds, 0, sumreq, v, n);
    return 0;
}
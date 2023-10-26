// Print subsequence with sum k
#include <bits/stdc++.h>
using namespace std;
void print(int indx, vector<int> &ds, int s, int sum, vector<int> &v, int n)
{
    if (indx == n)
    {
        if (sum == s)
        {
            for (auto &it : ds)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }
    // take the particular index into the subsequence
    ds.push_back(v[indx]);
    s += v[indx];
    print(indx + 1, ds, s, sum, v, n);
    s -= v[indx];
    ds.pop_back();
    // not take the particular index into the subsequence
    print(indx + 1, ds, s, sum, v, n);
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
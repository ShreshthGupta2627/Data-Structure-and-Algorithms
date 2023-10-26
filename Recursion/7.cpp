// Recursion on subsequence
// A contiguous or non-contiguos sequences , which follows the order
// Ex: [3,1,2]: subsequence :[{},{3},{1},{2},{3,1},{1,2},{3,2},{3,1,2}]

#include <bits/stdc++.h>
using namespace std;
void print(int indx, vector<int> &ds, vector<int> &v, int n)
{
    if (indx == n)
    {
        for (auto &it : ds)
        {
            cout << it << " ";
        }
        cout << endl;
        return;
    }
    // take the particular index into the subsequence
    ds.push_back(v[indx]);
    print(indx + 1, ds, v, n);
    // not take the particular index into the subsequence
    ds.pop_back();
    print(indx + 1, ds, v, n);
}
// Time complexity : O((2^n)*n)
// stack space=O(n)
int main()
{
    vector<int> v = {3, 1, 2};
    int n = 3;
    vector<int> ds;
    print(0, ds, v, n);
    return 0;
}
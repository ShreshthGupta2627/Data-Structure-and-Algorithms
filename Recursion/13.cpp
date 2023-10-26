// Subset sum 1
// Given list of N integers we need to print sum of all subsets , output should be in increasing order

// 1st methode use brute force i.e. powe set which generate all subset in (2 ^ n) * n
// 2nd methode recursive solution using select and not select on index of array
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void findsum(int indx, int sum, vector<int> &arr, int n, vector<int> &sumSubset)
    {
        if (indx == n)
        {
            sumSubset.push_back(sum);
            return;
        }
        // Pick the element
        findsum(indx + 1, sum + arr[indx], arr, n, sumSubset);
        // Not picking element
        findsum(indx + 1, sum, arr, n, sumSubset);
    }
    vector<int> subsetSums(vector<int> &arr, int N)
    {
        vector<int> sumSubset;
        findsum(0, 0, arr, N, sumSubset);
        sort(sumSubset.begin(), sumSubset.end());
        return sumSubset;
    }
};
int main()
{
    Solution s;
    vector<int> v = {1, 2};
    int n = 2;
    vector<int> ans = s.subsetSums(v, n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
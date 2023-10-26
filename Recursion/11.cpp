/*Combination Sum recursion

 Given an array of distinct integer candidate ans a target integer target return a list of all unique combination of candidates where the chosen number sum to target you may return combination in any order the same number can be chosen from candidates unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different

Ex : [2,3,6,7], target=7  ans:[{2,2,3},{7}]*/

// printing combination / subsequences think for recursion
// picking up element from array means think in the way of pick and not pick thought process

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void findComb(int ind, int target, vector<int> &a, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (ind == a.size())
        {
            if (target == 0)
            {
                ans.push_back(ds);
            }
            return;
        }
        // pick up the element
        if (a[ind] <= target)
        {
            ds.push_back(a[ind]);
            findComb(ind, target - a[ind], a, ans, ds);
            ds.pop_back();
        }
        findComb(ind + 1, target, a, ans, ds);
    }
    vector<vector<int>> CombinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> ans;
        vector<int> ds;
        findComb(0, target, candidates, ans, ds);
        return ans;
    }
};

int main()
{
    vector<int> v1 = {2, 3, 6, 7};
    vector<vector<int>> ansf;
    Solution s;
    int target = 7;
    ansf = s.CombinationSum(v1, target);
    for (int i = 0; i < ansf.size(); i++)
    {
        for (int j = 0; j < ansf[0].size(); j++)
        {
            if (target >= 0)
            {
                cout << ansf[i][j] << " ";
                target -= ansf[i][j];
            }
        }
        cout << endl;
    }

    return 0;
}
/*Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.

Ex: Input: candidates = {10,1,2,7,6,1,5}, target = 8
Output: {{1,1,6},{1,2,5},{1,7},{2,6}}  all are lexographically sorted*/

// One of the solution is changing indx to indx +1 in previous solution and take set<vector> intsted of vector of vector then convert it back to vector<vrctor>and return it but in this case tc= (2^t)*k*log(m) but we can reduce  log(m)

// Intution is that dont take consequtive same element after sorting i.e avoid recursion call for it recursive call with target - A[indx] ans index from indx till n

#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void findCombination(int indx, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds)
    {
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }
        for (int i = indx; i < arr.size(); i++)
        {
            if (i > indx && arr[i] == arr[i - 1])
                continue;
            if (arr[i] > target)
                break;
            ds.push_back(arr[i]);
            findCombination(i + 1, target - arr[i], arr, ans, ds);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> combSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> ds;
        findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};
int main()
{
    vector<int> v = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    Solution s;
    vector<vector<int>> ans = s.combSum2(v, target);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
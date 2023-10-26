// Subset sum2
/*Given an integer array nums that may contain duplicates , return all posible subsets (the power set) The solution set must not contain duplicate subsets , return the solution in any order
nums = {1,2,2} Output : {{},{1},{1,2},{1,2,2},{2},{2,2}}*/

// Approch 1: Just use pick not pick , and make all subsets once made you can just put them in set , but it will take an extra amount of time to put them up into the set therefore we need to optime the code

// Approch 2: Start with subset of len 1 till n such that the duplicate ones are not included while making the recursive call

// Ex : {1 , 2 , 2 , 2 , 3 , 3 }  = {},{1},{2},{3},{1,2},{1,3}......      after picking 2 of len 1 we ignore all other  , after picking {1,2} of len 2 we ignore all other 2 generating len 2 {1,2}  simply we can say ith lvl of rec. is generating subset of len i starting from lvl 0

// If an index is called for first time then we dont need to chk prev one we can directly aad it up
#include <bits/stdc++.h>
using namespace std;
void findSubset(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
{
    ans.push_back(ds);
    for (int i = ind; i < nums.size(); i++)
    {
        if (i != ind && nums[i] == nums[i - 1])
            continue;
        ds.push_back(nums[i]);
        findSubset(ind + 1, nums, ds, ans);
        ds.pop_back();
    }
}
vector<vector<int>> SubsetWithoutDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(), nums.end());
    findSubset(0, nums, ds, ans);
    return ans;
}
int main()
{
    vector<int> v = {1, 2, 2, 2, 3, 3};
    vector<vector<int>> ans = SubsetWithoutDup(v);
    for (auto &it : ans)
    {
        cout << "{ ";
        for (auto &i : it)
        {
            cout << i << " ";
        }
        cout << "}" << endl;
    }
    return 0;
}
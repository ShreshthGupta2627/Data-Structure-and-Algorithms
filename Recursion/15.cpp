// Print all the permutations of string / array
#include <bits/stdc++.h>
using namespace std;
// Approch 1: Using a map and adata structure select first element (any one) mark it in map and continue picking up till all are marked
void findperm(vector<int> &nums, vector<vector<int>> &ans, vector<int> &ds, map<int, bool> &mp)
{
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (!mp[i])
        {
            ds.push_back(nums[i]);
            mp[i] = 1;
            findperm(nums, ans, ds, mp);
            mp[i] = 0;
            ds.pop_back();
        }
    }
}
vector<vector<int>> perm(vector<int> &v)
{
    vector<vector<int>> ans;
    vector<int> ds;
    map<int, bool> mp;
    for (int i = 0; i < v.size(); i++)
    {
        mp[i] = 0;
    }
    findperm(v, ans, ds, mp);
    return ans;
}
int main()
{
    vector<int> v = {1, 2, 3};
    vector<vector<int>> ans = perm(v);
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
// Print all the permutation of string / array witout using map
#include <bits/stdc++.h>
using namespace std;
// Approch : Make a ptr to index and just swap the number with the no at ptr ind and proccede till the end onc ptr goes beyond the size just add that subset to ans
void findperm(int ind, vector<int> &nums, vector<vector<int>> &ans)
{
    if (ind == nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for (int i = ind; i < nums.size(); i++)
    {
        swap(nums[ind], nums[i]);
        findperm(ind + 1, nums, ans);
        swap(nums[ind], nums[i]);
    }
}
vector<vector<int>> perm(vector<int> &v)
{
    vector<vector<int>> ans;
    findperm(0, v, ans);
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
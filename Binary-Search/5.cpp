// Search element in rotated sorted array
// Ex: {4,5,6,7,0,1,2}; target :0  || o/p : 4 if not found return -1
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &v, int target)
{
    // 1st approch linear search
    int low = 0, high = v.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (v[mid] == target)
            return mid;
        if (v[low] <= v[mid])
        {
            if (v[low] <= target && v[mid] >= target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (v[mid] <= target && v[high] >= target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}
int main()
{
    vector<int> v = {4, 5, 6, 7, 0, 1, 2};
    int target = 4;
    cout << solve(v, target) << endl;
    return 0;
}
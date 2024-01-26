// Median of two sorted arrays
#include <bits/stdc++.h>
using namespace std;
float solve(vector<int> &a, vector<int> &b)
{
    // 1st methode merge two sorted array into a sorted array using merge sort and find median
    if (b.size() < a.size())
        return solve(b, a);
    int n1 = a.size(), n2 = b.size();
    int low = 0, high = n1;
    while (low <= high)
    {
        int cut1 = (low + high) >> 1;
        int cut2 = (n1 + n2 + 1) / 2 - cut1; //+1 to handle the odd case togather
        // handling the edge cases

        int left1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
        int left2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
        int right1 = (cut1 == n1) ? INT_MAX : a[cut1];
        int right2 = (cut2 == n2) ? INT_MAX : b[cut2];
        if (left1 <= right2 && left2 <= right1)
        {
            if ((n1 + n2) % 2 == 0)
            {
                return (max(left1, left2) + min(right1, right2)) / 2.0;
            }
            else
            {
                return max(left1, left2);
            }
        }
        else if (left1 > right2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }
    return 0.0;
}
int main()
{
    vector<int> v1 = {7, 12, 14, 15};
    vector<int> v2 = {1, 2, 3, 4, 9, 11};
    cout << solve(v2, v1) << endl;
    return 0;
}
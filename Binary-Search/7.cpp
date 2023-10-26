/*Given two sorted arrays arr1 and arr2 of size N and M respectively and an element K. The task is to find the element that would be at the k’th position of the final sorted array.*/
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &a, vector<int> &b, int k)
{
    // 1st approch is that we will take a conter and increase its value as we select any value when counter reaches 0 we gwt ans TC : O(k)  SC : O(1)
    if (b.size() < a.size())
        return solve(b, a, k);
    int n1 = a.size(), n2 = b.size();
    int low = max(0, k - n2), high = min(n1, k);
    while (low <= high)
    {
        int cut1 = (low + high) >> 1;
        int cut2 = k - cut1;
        int left1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
        int left2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
        int right1 = (cut1 == n1) ? INT_MAX : a[cut1];
        int right2 = (cut2 == n2) ? INT_MAX : b[cut2];
        if (left1 <= right2 && left2 <= right1)
        {
            if ((n1 + n2) % 2 == 0)
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
    return 0; // never get executed
}
int main()
{
    vector<int> v1 = {7, 12, 14, 15};
    vector<int> v2 = {1, 2, 3, 4, 9, 11};
    cout << solve(v2, v1, 5) << endl;
    return 0;
}
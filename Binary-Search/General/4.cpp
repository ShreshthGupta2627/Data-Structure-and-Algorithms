// Single element is sorted array and other apper twice
// Ex : {1,1,2,3,3,4,4,5,5,6,6}; o/p : 2
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &v)
{
    // one of the approch is traverse and take xor this is first that we need to tell interviwer
    // whenevr such a breakpoint occour in the left half we have the occurence as odd index -> second occurence and even index -> first occurence but after the breakpoints the things are going to reverse i.e even index -> second occurence and odd index -> first occurence
    // we will shink till low <= high if we are on right half move high to mid else if we are on left half move low to mid left and right half are decided using above condition
    // we take HIGH at 2nd Last element as if it is breakpoint then our low can cross high

    // Xor property : x^1 will give next odd if x is even and it will give prev even if x is odd
    int low = 0, high = v.size() - 2;
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        // Using mid^1 we avoid writing multiple condition for checking prev and next
        if (v[mid] == v[mid ^ 1])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return v[low];
}
int main()
{
    vector<int> v = {1, 1, 2, 3, 3, 4, 4, 5, 5, 6, 6};
    cout << solve(v) << endl;
    return 0;
}
// LIS using binary search
#include <bits/stdc++.h>
using namespace std;
int lcs(vector<int> &a)
{
    int n = a.size();
    vector<int> temp;
    temp.push_back(a[0]);
    for (int i = 1; i < n; i++)
    {
        if (a[i] > temp.back())
        {
            temp.push_back(a[i]);
        }
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin();
            temp[ind] = a[i];
        }
    }
    return temp.size();
}
int main()
{
    vector<int> a = {1, 7, 8, 4, 5, 6, -1, 9};
    cout << lcs(a) << endl;
    return 0;
}
// Median of a row wise sorted matrix
/*
 Matrix will be of order m * n where m*n is odd
 How we came to know that we can implement bs

 Matrix:
   1  3  6
   2  6  9
   3  6  9

   =>1  --->  1       =>2  --->  2
   =>3  --->  4       =>6  --->  7
   =>9  --->  9

   showing monotonicity
   conidering +ve int our no lie b/w 1 t0 e9 our serch space initially wil;l be this which will shrink down as per req
*/
#include <bits/stdc++.h>
using namespace std;
int count_lessThen(vector<int> &row, int mid)
{
    // we can even use upperbound
    int l = 0, h = row.size() - 1;
    while (l <= h)
    {
        mid = (l + h) >> 1;
        if (row[mid] <= mid)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return l;
}
int find_median(vector<vector<int>> &v)
{
    int low = 1, high = 1e9;
    int n = v.size();
    int m = v[0].size();
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cnt += count_lessThen(v[i], mid);
        }
        if (cnt <= (n * m) / 2)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
int main()
{
    vector<vector<int>> v = {{1, 3, 6}, {2, 6, 9}, {3, 6, 9}};
    cout << find_median(v) << endl;
    return 0;
}
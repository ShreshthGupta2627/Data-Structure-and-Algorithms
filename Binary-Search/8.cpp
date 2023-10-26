/*Given an array of integers A of size N and an integer B.

The College library has N books. The ith book has A[i] number of pages.

You have to allocate books to B number of students so that the maximum number of pages allocated to a student is minimum.

1.A book will be allocated to exactly one student.
2.Each student has to be allocated at least one book.
3.Allotment should be in contiguous order, for example: A student cannot be allocated book 1 and book 3, skipping book 2.
4.Calculate and return that minimum possible number.

NOTE: Return -1 if a valid assignment is not possible.*/
#include <bits/stdc++.h>
using namespace std;
bool allocation_possible(vector<int> &v, int barrier, int s)
{
    int student_cnt = 0, pages = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (pages > barrier)
        {
            return false;
        }
        if (pages + v[i] > barrier)
        {
            student_cnt++;
            pages += v[i];
        }
        else
        {
            pages += v[i];
        }
    }
    if (student_cnt > s)
        return false;
    return true;
}
int solve(vector<int> &v, int s)
{
    // can be solved using dp
    // bs is more optimal
    // serch space is min_element to sum as min page in case of equal is min and all to one is max
    // we create mid and see if i can allocate books with less than this and stu count is maintained if no remove left part if yes remove right part
    int low = *min_element(v.begin(), v.end()), high = 0, res = -1;
    for (int i = 0; i < v.size(); i++)
    {
        high += v[i];
    }
    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (allocation_possible(v, mid, s))
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}
int main()
{
    vector<int> v = {12, 34, 67, 90};
    int s = 2;
    cout << solve(v, s);
    return 0;
}
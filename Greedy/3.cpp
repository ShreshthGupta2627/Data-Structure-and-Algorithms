/*There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?
Note: Start time of one chosen meeting can't be equal to the end time of the other chosen meeting , in case of equal finishing time maintain the order

Input:
N = 6
start[] = {1,3,0,5,8,5}
end[] =  {2,4,6,7,9,9}
Output:
4
Explanation:
Maximum four meetings can be held with
given start and end timings.
The meetings are - (1, 2),(3, 4), (5,7) and (8,9)
*/

#include <bits/stdc++.h>
using namespace std;
struct meeting
{
    int start;
    int end;
    int pos;
};
bool cmp(meeting m1, meeting m2)
{
    if (m1.end < m2.end)
        return true;
    else if (m1.end > m2.end)
        return false;
    else if (m1.pos < m2.pos)
        return true;
    return false;
}
vector<int> MaxMeetings(vector<int> &s, vector<int> &e, int n)
{
    vector<meeting> meet(n);
    for (int i = 0; i < n; i++)
    {
        meet[i].start = s[i], meet[i].end = e[i], meet[i].pos = i + 1;
    }
    sort(meet.begin(), meet.end(), cmp);
    vector<int> ans;
    int last_end = meet[0].end;
    ans.push_back(meet[0].pos);
    for (int i = 1; i < n; i++)
    {
        if (meet[i].start > last_end)
        {
            last_end = meet[i].end;
            ans.push_back(meet[i].pos);
        }
    }
    return ans;
}
int main()
{
    int n = 6;
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};
    vector<int> print = MaxMeetings(start, end, n);
    for (auto &it : print)
    {
        cout << it << " ";
    }
    // Tc : O(n){intitial traversal} + O(nlogn){sorting} +O(n){agin traversal} + O(2*n){copy and print}
    return 0;
}
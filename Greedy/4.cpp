// Minimum number of platforms required for railways
/*Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.
Input: n = 6
arr[] = {09:00, 09:40, 09:50, 11:00, 15:00, 18:00}
dep[] = {09:10, 12:00, 11:20, 11:30, 19:00, 20:00}
Output: 3
Explanation:
Minimum 3 platforms are required to
safely arrive and depart all trains. */

// Sort both the arriving time and the departure time in ascending orders seperately dont care abt order to be maintained it doesnt matters

#include <bits/stdc++.h>
using namespace std;
int findPlatform(vector<int> &arrival, vector<int> &departure, int n)
{
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());
    int plat_req = 1, max_plat_cnt = 1;
    int i = 1, j = 0;
    while (i < n && j < n)
    {
        if (arrival[i] <= departure[j])
        {
            plat_req++;
            i++;
        }
        else if (arrival[i] > departure[j])
        {
            plat_req--;
            j++;
        }
        max_plat_cnt = max(max_plat_cnt, plat_req);
    }
    return max_plat_cnt;
}
int main()
{
    int n = 6;
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    cout << findPlatform(arr, dep, arr.size());
    return 0;
}
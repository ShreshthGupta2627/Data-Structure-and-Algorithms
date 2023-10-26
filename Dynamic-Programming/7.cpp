/* ninja is planing this n days long training schedule each day he can perform any one of these three activities running fighting practice or learning new moves each activity has some merit points on each day as ninja has to improve allhis skills he can t do the same activity in two consecutive days can you help ninja find out the maximum merit points ninja can earn
Example:

If the given ‘POINTS’ array is [[1,2,5], [3 ,1 ,1] ,[3,3,3] ],the answer will be 11 as 5 + 3 + 3.
*/
#include <bits/stdc++.h>
using namespace std;
int solve(int day, int last, vector<vector<int>> &points)
{
    if (day == 0)
    {
        int maxx = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                maxx = max(maxx, points[0][i]);
            }
        }
        return maxx;
    }
    int maxx = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int point = points[day][i] + solve(day - 1, i, points);
            maxx = max(maxx, point);
        }
    }
    return maxx;
}
int solve_with_memoization(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxx = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                maxx = max(maxx, points[0][i]);
            }
        }
        return dp[day][last] = maxx;
    }
    if (dp[day][last] != -1)
        return dp[day][last];
    int maxx = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int point = points[day][i] + solve_with_memoization(day - 1, i, points, dp);
            maxx = max(maxx, point);
        }
    }
    return dp[day][last] = maxx;
}
int solve_with_tabulation(int days, int n_act, vector<vector<int>> &points)
{
    vector<vector<int>> dp(days, vector<int>(n_act, 0));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] == max(points[0][0], max(points[0][1], points[0][2]));
    for (int day = 1; day < days; day++)
    {
        for (int last = 0; last < n_act; last++)
        {
            dp[day][last] = 0;
            for (int task = 0; task < n_act - 1; task++)
            {
                if (task != last)
                {
                    int point = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }
    return dp[days - 1][n_act - 1];
}
int solve_space_optimized(int days, int n_act, vector<vector<int>> &points)
{
    vector<int> prev(n_act, 0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));
    for (int day = 1; day < days; day++)
    {
        vector<int> temp(n_act, 0);
        for (int last = 0; last < n_act; last++)
        {
            temp[last] = 0;
            for (int task = 0; task < n_act - 1; task++)
            {
                if (task != last)
                {
                    temp[last] = max(temp[last], points[day][task] + prev[task]);
                }
            }
        }

        prev = temp;
    }

    return prev[n_act - 1];
}
int main()
{
    int n = 4, m = 4; // 4 ms 0 for 1st 1 for 2nd  2 for 3rd and 3 for selecting none
    vector<vector<int>> points = {{2, 1, 3}, {3, 4, 6}, {10, 1, 6}, {8, 3, 7}};
    cout << solve(n - 1, m - 1, points) << endl;
    // zero based indexing n --> 0,1,2.......n-1        m -->0,1,2,3.......m-1
    vector<vector<int>> dp(n, vector<int>(m, -1));
    cout << solve_with_memoization(n - 1, m - 1, points, dp) << endl;
    cout << solve_with_tabulation(4, 4, points) << endl;
    cout << solve_space_optimized(n, m, points) << endl;
    return 0;
}
// Job sequencing problem
/*Given a set of N jobs where each jobi has a deadline and profit associated with it.
Each job takes 1 unit of time to complete and only one job can be scheduled at a time. We earn the profit associated with job if and only if the job is completed by its deadline.
Find the number of jobs done and the maximum profit.
Note: Jobs will be given in the form (Jobid, Deadline, Profit) associated with that Job.

Input:
N = 4
Jobs = {(1,4,20),(2,1,10),(3,1,40),(4,1,30)}
Output:
2 60
Explanation:
Job1 and Job3 can be done with
maximum profit of 60 (20+40).
*/
#include <bits/stdc++.h>
using namespace std;
struct job
{
    int id;
    int deadline;
    int profit;
};

bool cmp(job a, job b)
{
    return a.profit > b.profit;
}
pair<int, int> jobScheduling(vector<job> arr, int n)
{
    sort(arr.begin(), arr.end(), cmp);
    int maxx = arr[0].deadline;
    for (int i = 1; i < n; i++)
    {
        maxx = max(maxx, arr[i].deadline);
    }
    vector<int> taken(maxx + 1, -1);
    int cntJob = 0, jobProfit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].deadline; j > 0; j--)
        {
            if (taken[j] == -1)
            {
                taken[j] = i;
                cntJob++;
                jobProfit += arr[i].profit;
                break;
            }
        }
    }
    return make_pair(cntJob, jobProfit);
}
int main()
{
    int n = 4;
    vector<job> Jobs = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    pair<int, int> p = jobScheduling(Jobs, n);
    cout << p.first << " " << p.second << endl;
    return 0;
}
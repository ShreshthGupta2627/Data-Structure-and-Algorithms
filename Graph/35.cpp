// Minimum Multiplication to reach end
/*Given start, end, and an array arr of n numbers. At each step, the start is multiplied by any number in the array and then a mod operation with 100000 is done to get the new start.
Your task is to find the minimum steps in which the end can be achieved starting from the start. If it is not possible to reach the end, then return -1.*/

#include <bits/stdc++.h>
using namespace std;
void solve(int start, int end, vector<int> &a)
{
    int steps = 0;
    if (start == end)
    {
        cout << 0 << endl;
        return;
    }

    vector<int> dist(100001, 1e9);
    dist[start] = 0;

    queue<pair<int, int>> q;
    // Since at each level step cnt increase by 1 :. No need of priority queue
    // Tc : O(1e5 * N)
    q.push({0, start});
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();

        int CntStep = curr.first;
        int CurrNode = curr.second;

        for (auto &it : a)
        {
            int num = (it * CurrNode) % 100000;
            if (CntStep + 1 < dist[num])
            {
                if (num == end)
                {
                    cout << CntStep + 1 << endl;
                    return;
                }
                q.push({CntStep + 1, num});
            }
        }
    }
    cout << -1 << endl;
}
int main()
{
    int start = 7, end = 66175;
    vector<int> a = {3, 4, 65};
    solve(start, end, a);
    return 0;
}
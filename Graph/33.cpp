// Path with minimum effort
/*You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.
A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.*/

#include <bits/stdc++.h>
using namespace std;

int MinEfforts(vector<vector<int>> &height)
{
    int n = height.size();
    int m = height[0].size();

    // {diff, {row, col}}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[0][0] = 0;

    pq.push({0, {0, 0}});
    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();

        int diff = curr.first;
        int row = curr.second.first;
        int col = curr.second.second;

        if (row == n - 1 && col == m - 1)
        {
            return diff;
        }

        vector<int> drow = {-1, 0, 1, 0};
        vector<int> dcol = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++)
        {
            int nr = row + drow[i];
            int nc = col + dcol[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m)
            {
                int newEffort = max(abs(height[row][col] - height[nr][nc]), diff);
                if (dist[nr][nc] > newEffort)
                {
                    dist[nr][nc] = newEffort;
                    pq.push({dist[nr][nc], {nr, nc}});
                }
            }
        }
    }
    return -1;
}
int main()
{
    vector<vector<int>> height = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};
    cout << MinEfforts(height) << endl;
    return 0;
}
// Shortest path in binary maze
/*Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1.

If the path is not possible between source cell and destination cell, then return -1.

Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they share a side. In other words, you can move in one of the four directions, Up, Down, Left and Right. The source and destination cell are based on the zero based indexing.
To move form 1 cell to another cost will be 1 (assume) */

#include <bits/stdc++.h>
using namespace std;

void dijakstra(pair<int, int> &start, pair<int, int> &end, vector<vector<int>> &maze)
{
    if (start.first == end.first && start.second == end.second)
    {
        cout << 0 << endl;
        return;
    }
    int n = maze.size();
    int m = maze[0].size();

    vector<int> drow = {-1, 0, 1, 0};
    vector<int> dcol = {0, 1, 0, -1};

    queue<pair<int, pair<int, int>>> q;
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[start.first][start.second] = 0;

    q.push({0, {start}});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        int dis = it.first;
        int row = it.second.first;
        int col = it.second.second;

        for (int i = 0; i < 4; i++)
        {
            int nr = row + drow[i];
            int nc = col + dcol[i];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && maze[nr][nc] == 1 && dis + 1 < dist[nr][nc])
            {
                dist[nr][nc] = 1 + dis;
                q.push({dis + 1, {nr, nc}});

                if (nr == end.first && nc == end.second)
                {
                    cout << dis + 1 << endl;
                    return;
                }
            }
        }
    }
    cout << -1 << endl;
}
int main()
{
    vector<vector<int>> maze = {{1, 1, 1, 1}, {1, 1, 0, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}, {1, 0, 0, 1}};
    pair<int, int> start = {0, 1}, end = {2, 2};
    dijakstra(start, end, maze);
    return 0;
}
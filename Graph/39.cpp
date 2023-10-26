// Find the City With the Smallest Number of Neighbours at a Threshold Distance
/*There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi,weighti]  represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distance Threshold. You need to find out a city with the smallest number of cities that are reachable through some path and whose distance is at most Threshold Distance, If there are multiple such cities, our answer will be the city with the greatest number.

Note: that the distance of a path, connecting cities i and j are equal to the sum of the edges’ weights along that path.*/

#include <bits/stdc++.h>
using namespace std;

void Solve(int threshold, vector<vector<int>> &cost)
{
    // Applying Flloyd Warshall
    int n = cost.size();
    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (cost[i][via] != 1e9 && cost[via][j] != 1e9)
                {
                    cost[i][j] = min(cost[i][j], cost[i][via] + cost[via][j]);
                }
            }
        }
    }

    int MaxCnt = n + 1;
    int Cnt = 0;
    int City = -1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cost[i][j] <= threshold)
            {
                Cnt++;
            }
        }
        if (MaxCnt >= Cnt)
        {
            MaxCnt = Cnt;
            City = i;
        }
        Cnt = 0;
    }

    cout << City << endl;
}

void fill(vector<vector<int>> &cost, int u, int v, int EdgeCost)
{
    cost[u][v] = EdgeCost;
    cost[v][u] = EdgeCost;
}
int main()
{
    int sz = 4;
    vector<vector<int>> dist(sz, vector<int>(sz, 1e9));
    for (int i = 0; i < sz; i++)
    {
        dist[i][i] = 0;
    }

    fill(dist, 0, 1, 3);
    fill(dist, 1, 2, 1);
    fill(dist, 1, 3, 4);
    fill(dist, 2, 3, 1);

    int threshold = 4;
    Solve(threshold, dist);
    return 0;
}
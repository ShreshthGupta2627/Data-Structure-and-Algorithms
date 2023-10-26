// Flloyd Warsol algorithm

#include <bits/stdc++.h>
using namespace std;

void FlloydWarshall(vector<vector<int>> &cost)
{
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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << cost[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        if (cost[i][i] < 0)
        {
            cout << "Has -ve Wt Cycle" << endl;
            break;
        }
    }
}

void fill(vector<vector<int>> &cost, int u, int v, int EdgeCost)
{
    cost[u][v] = EdgeCost;
}
int main()
{
    int sz = 4;
    vector<vector<int>> cost(sz, vector<int>(sz, 1e9));
    for (int i = 0; i < sz; i++)
    {
        cost[i][i] = 0;
    }

    fill(cost, 0, 1, 2);
    fill(cost, 1, 0, 1);
    fill(cost, 1, 2, 3);
    fill(cost, 3, 0, 3);
    fill(cost, 3, 1, 5);
    fill(cost, 3, 2, 4);

    FlloydWarshall(cost);
    return 0;
}
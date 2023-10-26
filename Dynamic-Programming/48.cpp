// Min Cost to cut the stick
/*We are given a stick of length N and a CUTS array of size C. The stick has markings as shown, and the CUTS array depicts the marking at which the stick needs to be cut.
Whenever we make a cut, we incur a cost. This cost is equal to the length of the stick on which we are making the cut.
We need to find the minimum cost incurred to cut the stick at all the cut points.
Note: It is necessary to make cuts at all the red markings present in cut array.*/

#include <bits/stdc++.h>
using namespace std;
int rec(int i, int j, vector<int> &cuts)
{
    if (i > j)
        return 0;
    int minCost = INT_MAX;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = (cuts[j + 1] - cuts[i - 1]) + rec(i, ind - 1, cuts) + rec(ind + 1, j, cuts);
        minCost = min(minCost, cost);
    }
    return minCost;
}

int mem(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int minCost = INT_MAX;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = (cuts[j + 1] - cuts[i - 1]) + mem(i, ind - 1, cuts, dp) + mem(ind + 1, j, cuts, dp);
        minCost = min(minCost, cost);
    }
    return dp[i][j] = minCost;
}

int tab(int n, vector<int> &cuts)
{
    //-2 for extra insertion removal count
    int c = cuts.size() - 2;
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));
    for (int i = 0; i < c + 1; i++)
    {
        for (int j = 0; j < c + 1; j++)
        {
            if (i > j)
                dp[i][j] = 0;
        }
    }

    for (int i = c; i >= 1; i--)
    {
        for (int j = 1; j <= c; j++)
        {
            if (i > j)
                continue;
            int minCost = 1e7;
            for (int ind = i; ind <= j; ind++)
            {
                int cost = (cuts[j + 1] - cuts[i - 1]) + dp[i][ind - 1] + dp[ind + 1][j];
                minCost = min(minCost, cost);
            }
            dp[i][j] = minCost;
        }
    }
    return dp[1][c];
}
int main()
{
    int len = 7, c = 4;
    vector<int> cuts = {1, 3, 4, 5};
    cuts.push_back(0);
    cuts.push_back(len);
    sort(cuts.begin(), cuts.end());
    cout << rec(1, c, cuts) << endl;

    vector<vector<int>> dp(len + 1, vector<int>(c + 1, -1));
    cout << mem(1, c, cuts, dp) << endl;

    cout << tab(len, cuts) << endl;
    return 0;
}
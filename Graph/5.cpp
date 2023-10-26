// Number of proviences

/* Given an undirected graph with V vertices.We say two vertices u and v belongs to a single provience if there is a path from u to v your task is to find number of proviences */

#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void dfs(int node, vector<vector<int>> adj_list, int *vis)
    {
        vis[node] = 1;
        for (auto &i : adj_list[node])
        {
            if (!vis[i])
            {
                dfs(i, adj_list, vis);
            }
        }
    }

public:
    int numProviences(vector<vector<int>> &v, int n)
    {
        /*Creating list*/
        vector<vector<int>> adj_list(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (v[i][j] == 1 && i != j)
                {
                    adj_list[i].push_back(j);
                    adj_list[j].push_back(i);
                }
            }
        }
        int vis[n] = {0};
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                cnt++;
                dfs(i, adj_list, vis);
            }
        }
        return cnt;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> v = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};
    int n = v.size();
    cout << s.numProviences(v, n) << endl;
    // Time complexity :- O(n) + O(n+2*E) the second component is of overall runtime of dfs
    // Space complexity :- O(n) stack + O(n) array
    return 0;
}
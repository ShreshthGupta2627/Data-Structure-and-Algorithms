// Dfs traversal of a graph we need to go to depth :. we will use recursion
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    void dfs(int node, vector<vector<int>> adj, int *vis, vector<int> &ls)
    {
        vis[node] = 1;
        ls.push_back(node);
        // Traverse all its neighbour
        for (auto &it : adj[node])
        {
            if (!vis[it])
            {
                dfs(it, adj, vis, ls);
            }
        }
    }

public:
    vector<int> DFS_of_Graph(int v, vector<vector<int>> adj)
    {
        int n = v;
        int vis[n] = {0};
        vis[0] = 1;
        int start = 1;
        vector<int> ls;
        dfs(start, adj, vis, ls);
        return ls;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> a = {{0}, {2, 6}, {1, 3, 4}, {2}, {2, 5}, {4, 8}, {1, 7, 9}, {6, 8}, {5, 7}, {6}};
    vector<int> ans = s.DFS_of_Graph(9, a);
    for (auto &it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    // space complexity O(n)+O(n)+O(n)=O(n)
    // Time complexity :- sum of degree for undirected graph O(n) for recursion and O(2*E) for neighbour traversal
    return 0;
}
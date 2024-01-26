// Bfs Traversal in Graph
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Number of nodes is V
    vector<int> BFS_of_Graph(int v, vector<vector<int>> &adj)
    {
        int n = v;
        int vis[n + 1] = {0};
        vis[0] = 1;
        queue<int> q;
        q.push(0);
        vector<int> bfs;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for (auto it : adj[node])
            {
                if (!vis[it])
                {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return bfs;
        // Space complexity =O(3*n + n*n [ list given ])
        // Time compleity :- s
        // Node goes once into the bfs , while run on all its degree :. tc= O(n)+O(2*E)
    }
};
int main()
{
    Solution s;
    int n = 9;
    vector<vector<int>> a = {{0}, {2, 6}, {1, 3, 4}, {2}, {2, 5}, {4, 8}, {1, 7, 9}, {6, 8}, {5, 7}, {6}};
    vector<int> ans = s.BFS_of_Graph(9, a);
    for (auto &it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
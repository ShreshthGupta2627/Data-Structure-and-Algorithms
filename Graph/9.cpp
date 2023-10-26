// Cycle detection in a undirectional graph using bfs
#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool detect(int src, vector<int> adj[], vector<int> &vis)
    {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (auto adjacentNode : adj[node])
            {
                if (!vis[adjacentNode])
                {
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                }
                else if (parent != adjacentNode)
                {
                    // if someone is visited and it does not come from there then someone at same level have priorily visited the node ==> cycle it there
                    return true;
                }
            }
        }
        return false;
    }
    // Seprate function for detection is their as their may be disconnected component of graph
public:
    bool isCycle(int cnt_node, vector<int> adj[])
    {
        vector<int> vis(cnt_node, 0);
        for (int i = 0; i < cnt_node; i++)
        {
            if (!vis[i])
                if (detect(i, adj, vis) == true)
                {
                    return true;
                }
        }
        return false;
        // Time Complexity : O(n+adjacent nodes)  adj nodes= 2e  =>  TC : O(n+2e)
        // Summition of adj nodes = sum of degrees = 2e (in undirected)
        // SC : O(n)
    }
};
int main()
{
    Solution s;
    vector<int> adj[4] = {{}, {2}, {1, 3}, {2}};
    vector<int> adj1[4] = {{1, 3}, {2}, {1, 3}, {2}};
    Solution obj;
    bool ans = obj.isCycle(4, adj);
    if (ans)
        cout << "1\n";
    else
        cout << "0\n";
    bool ans1 = obj.isCycle(4, adj1);
    if (ans1)
        cout << "1\n";
    else
        cout << "0\n";
    return 0;
}
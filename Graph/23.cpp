// course scedule 2
/* There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array. */
#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<int>> &adj)
{
    int n = adj.size();
    queue<int> q;

    vector<int> indegree(n, 0);
    vector<int> topoSort;
    for (int i = 0; i < n; i++)
    {
        for (auto &neig : adj[i])
        {
            indegree[neig]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        topoSort.push_back(curr);
        for (auto &it : adj[curr])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    reverse(topoSort.begin(), topoSort.end());
    if (topoSort.size() == n)
    {
        for (auto &it : topoSort)
        {
            cout << it << " ";
        }
    }
    else
    {
        topoSort.clear();
        cout << "Not possible" << endl;
    }
}
void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
}
int main()
{
    vector<vector<int>> adj(6);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);
    addEdge(adj, 4, 0);
    addEdge(adj, 4, 1);
    addEdge(adj, 5, 0);
    addEdge(adj, 5, 2);
    bfs(adj);
    return 0;
}
// Eventual safe state using toposort
/*There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].
A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).
Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.*/
#include <bits/stdc++.h>
using namespace std;

vector<int> EventualSafeNode(vector<vector<int>> &adj)
{
    int n = adj.size();
    // Reversing adjList

    vector<vector<int>> Revadj(n);
    for (int i = 0; i < n; i++)
    {
        // i->it
        // I need it -> i
        for (auto &it : adj[i])
        {
            Revadj[it].push_back(i);
        }
    }

    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto &it : Revadj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;
    vector<int> safeNodes;
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
        safeNodes.push_back(curr);
        for (auto &it : Revadj[curr])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }

    sort(safeNodes.begin(), safeNodes.end());
    for (auto &it : safeNodes)
    {
        cout << it << " ";
    }
    return safeNodes;
}

void addEdge(vector<vector<int>> &adj, int u, int v)
{
    adj[u].push_back(v);
}
int main()
{
    vector<vector<int>> adj(4);
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);
    EventualSafeNode(adj);
    return 0;
}
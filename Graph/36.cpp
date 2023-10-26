// Number of ways to arrive at destination
/*You are in a city that consists of n intersections numbered from 0 to n – 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array ‘roads’ where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n – 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.*/
#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
void NumWaysToDest(vector<vector<pair<int, int>>> &adj)
{
    int n = adj.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(n, 1e9), ways(n, 0);
    dist[0] = 0;
    // Already at 0 :. 1
    ways[0] = 1;

    pq.push({0, 0});
    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();
        int dis = curr.first;
        int node = curr.second;

        for (auto &it : adj[node])
        {
            int adjNode = it.first;
            int wt = it.second;

            if (dis + wt < dist[adjNode])
            {
                dist[adjNode] = dis + wt;
                pq.push({dist[adjNode], adjNode});

                ways[adjNode] = ways[node];
            }
            else if (dis + wt == dist[adjNode])
            {
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }
    cout << ways[n - 2] % mod << endl;
}
void addEdge(vector<vector<pair<int, int>>> &adj, int u, int v, int wt)
{
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
}
int main()
{
    vector<vector<int>> edges = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};
    vector<vector<pair<int, int>>> adj(8);
    for (auto &it : edges)
    {
        addEdge(adj, it[0], it[1], it[2]);
    }

    NumWaysToDest(adj);
    return 0;
}
// Cheapest flights with K steps
/*There are n cities and m edges connected by some number of flights. You are given an array of flights where flights[i] = [ fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost price. You have also given three integers src, dst, and k, and return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.*/
#include <bits/stdc++.h>
using namespace std;

int Dijaktras(int src, int dest, int k, vector<vector<pair<int, int>>> &adj)
{
    int n = adj.size();
    vector<int> dist(n, 1e9);
    dist[src] = 0;

    //{stops , {node , dist}}
    queue<pair<int, pair<int, int>>> q;

    // Tc:  E = adj.size()
    // If we use pq it will be E log (V)
    q.push({0, {src, 0}});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        int stop = it.first;
        int node = it.second.first;
        int cost = it.second.second;

        if (stop > k)
        {
            continue;
        }

        for (auto &neig : adj[node])
        {
            int curr = neig.first;
            int wt = neig.second;

            if (cost + wt < dist[curr] && stop <= k)
            {
                dist[curr] = cost + wt;
                q.push({stop + 1, {curr, dist[curr]}});
            }
        }
    }

    if (dist[dest] == 1e9)
    {
        return -1;
    }
    return dist[dest];
}
void addEdge(vector<vector<pair<int, int>>> &adj, int u, int v, int wt)
{
    adj[u].push_back({v, wt});
}
int main()
{

    int n = 4;
    vector<vector<pair<int, int>>> adj(n + 1);
    addEdge(adj, 0, 1, 100);
    addEdge(adj, 1, 2, 100);
    addEdge(adj, 2, 0, 100);
    addEdge(adj, 1, 3, 600);
    addEdge(adj, 2, 3, 200);

    cout << Dijaktras(0, 3, 1, adj) << endl;
    return 0;
}
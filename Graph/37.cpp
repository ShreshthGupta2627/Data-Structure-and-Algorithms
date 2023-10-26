// Bellman Ford Algorithm
/*Given a weighted, directed and connected graph of V vertices and E edges, Find the shortest distance of all the vertices from the source vertex S.*/
#include <bits/stdc++.h>
using namespace std;

void BellmanFord(int src, vector<int> &dist, vector<pair<int, pair<int, int>>> &edges)
{
    int n = edges.size();
    dist[src] = 0;
    for (int i = 0; i < n; i++)
    {
        for (auto &ed : edges)
        {
            if (dist[ed.first] + ed.second.second < dist[ed.second.first])
            {
                dist[ed.second.first] = dist[ed.first] + ed.second.second;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dist[i] << endl;
    }

    // Finding -ve cycle

    vector<int> dist1(dist.begin(), dist.end());
    for (auto &ed : edges)
    {
        if (dist1[ed.first] + ed.second.second < dist1[ed.second.first])
        {
            dist1[ed.second.first] = dist1[ed.first] + ed.second.second;
        }
    }

    if (dist == dist1)
    {
        cout << "Not having -ve wt cycle" << endl;
    }
    else
    {
        cout << "having -ve wt cycle" << endl;
    }
}
void addEdge(vector<pair<int, pair<int, int>>> &edges, int u, int v, int w)
{
    edges.push_back({u, {v, w}});
}
int main()
{
    vector<pair<int, pair<int, int>>> edges;
    addEdge(edges, 0, 1, 1);
    addEdge(edges, 1, 2, 1);
    addEdge(edges, 2, 3, 1);
    addEdge(edges, 3, 4, 1);
    // Having -ve cycle
    // addEdge(edges, 0, 1, 1);
    // addEdge(edges, 1, 2, -5);
    // addEdge(edges, 2, 1, 1);

    int n = edges.size();
    vector<int> dist(n, 1e9);
    BellmanFord(0, dist, edges);

    // Tc :V*E
    return 0;
}
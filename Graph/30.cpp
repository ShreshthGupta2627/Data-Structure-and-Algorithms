// Dijakstras Algorithm
#include <bits/stdc++.h>
using namespace std;
void Dijakstra(int src, vector<vector<pair<int, int>>> adj)
{
    int n = adj.size();
    // MinHeap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n, 1e9);
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty())
    {
        auto curr = pq.top();
        pq.pop();

        int wt = curr.first;
        int node = curr.second;

        for (auto &it : adj[node])
        {
            if (dist[it.first] > it.second + wt)
            {
                dist[it.first] = it.second + wt;
                pq.push({dist[it.first], it.first});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dist[i] << endl;
    }

    // TC : (no of edges) * (log(No of nodes))
}

void Dijakstra_set(int src, vector<vector<pair<int, int>>> adj)
{
    int n = adj.size();
    set<pair<int, int>> st;
    vector<int> dist(n, 1e9);
    dist[src] = 0;

    st.insert({0, src});
    while (!st.empty())
    {
        auto curr = *(st.begin());
        int node = curr.second;
        int wt = curr.first;
        st.erase(curr);

        for (auto &it : adj[node])
        {
            if (dist[it.first] > it.second + wt)
            {
                if (dist[it.first] != 1e9)
                {
                    st.erase(it);
                }

                dist[it.first] = it.second + wt;
                st.insert({dist[it.first], it.first});
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " -> " << dist[i] << endl;
    }
}
void addEdge(vector<vector<pair<int, int>>> &adj, int u, pair<int, int> v)
{
    adj[u].push_back(v);
}
int main()
{
    vector<vector<pair<int, int>>> adj(6);
    addEdge(adj, 0, {1, 4});
    addEdge(adj, 0, {2, 4});
    addEdge(adj, 1, {0, 4});
    addEdge(adj, 1, {2, 2});
    addEdge(adj, 2, {0, 4});
    addEdge(adj, 2, {1, 2});
    addEdge(adj, 2, {3, 3});
    addEdge(adj, 2, {4, 1});
    addEdge(adj, 2, {5, 6});
    addEdge(adj, 3, {2, 3});
    addEdge(adj, 3, {5, 2});
    addEdge(adj, 4, {2, 1});
    addEdge(adj, 4, {5, 3});
    addEdge(adj, 5, {3, 2});
    addEdge(adj, 5, {2, 6});
    addEdge(adj, 5, {4, 3});

    Dijakstra(0, adj);
    // Dijakstra_set(0, adj);
    return 0;
}
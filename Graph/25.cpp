// Alien Dictionary
/*Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. Find the order of characters in the alien language.
Note: Many orders may be possible for a particular test case, thus you may return any valid order and output will be 1 if the order of string returned by the function is correct else 0 denoting incorrect string returned.*/

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

    if (topoSort.size() == n)
    {
        for (auto &it : topoSort)
        {
            cout << (char)(it + 'a') << " ";
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
    int n = 5, k = 4;
    vector<string> s = {"baa", "abcd", "abca", "cab", "cad"};
    vector<vector<int>> adj(k);
    bool f = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < min(s[i].length(), s[i + 1].length()); j++)
        {
            if (s[i][j] != s[i + 1][j])
            {
                addEdge(adj, s[i][j] - 'a', s[i + 1][j] - 'a');
                f = 1;
                break;
            }
        }
        if (!f)
        {
            if (s[i].length() > s[i + 1].length())
            {
                cout << "Not possible" << endl;
                return 0;
            }
        }
        f = 0;
    }
    bfs(adj);
    return 0;
}
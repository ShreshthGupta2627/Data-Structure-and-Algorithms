// Vectors operation and nesting
#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Basic operations
    vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.pop_back();
    v2 = v1;
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v2[i] << " ";
    }
    cout << "\n";

    // Vectors of pair
    vector<pair<int, int>> v3;
    int n;
    cout << "Enter number of pairs you want to enter " << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v3.push_back({x, y});
    }
    for (int i = 0; i < v3.size(); i++)
    {
        cout << v3[i].first << " " << v3[i].second << endl;
    }
    cout << endl;

    // Vectors of vector
    vector<vector<int>> v4;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int m;
        cin >> m;
        vector<int> temp;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        v4.push_back(temp);
    }
    for (int i = 0; i < v4.size(); i++)
    {
        for (int j = 0; j < v4[i].size(); j++)
        {
            cout << v4[i][j] << " ";
        }
    }
    return 0;
}
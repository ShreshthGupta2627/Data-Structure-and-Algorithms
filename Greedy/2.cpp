// Minimum Coins
//  Minimum number of coins to reach a value , coin should be one among { 1, 2, 5, 10,20, 50, 100, 200, 500, 2000 }

// In case of {1,5,6,9} to make up 11 acc to greedy ans is 3 i.e 9 + 1 + 1 but in real we can give 5 + 6 here greedy will fail where sum of two conseq exceeds the 3rd one
#include <bits/stdc++.h>
using namespace std;
vector<int> solve(int target)
{
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    vector<int> ans;
    for (int i = coins.size() - 1; i >= 0; i--)
    {
        while (target >= coins[i])
        {
            target -= coins[i];
            ans.push_back(coins[i]);
        }
    }
    return ans;
}
int main()
{
    int v = 87;
    vector<int> print = solve(v);
    for (auto &it : print)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}
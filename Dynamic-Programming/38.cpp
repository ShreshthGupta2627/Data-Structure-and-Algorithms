// Best time to buy and sell stock 4
/*We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:
1. We can buy and sell the stock any number of times.
2. In order to sell the stock, we need to first buy it on the same or any previous day.
3. We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After
   selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any previously
   bought stock.
4. We can do at-most K transactions.*/

#include <bits/stdc++.h>
using namespace std;

// Can be done by changing 2 to k in prev ques but lets see other methode that we have seen in last question met2
int rec(int ind, int trans, vector<int> &price, int k)
{
    int n = price.size();
    if (ind == n || trans == 2 * k)
    {
        return 0;
    }
    if (trans % 2 == 0)
    {
        // Buy
        int Buy = -price[ind] + rec(ind + 1, trans + 1, price, k);
        int notBuy = 0 + rec(ind + 1, trans, price, k);
        return max(Buy, notBuy);
    }
    else
    {
        // Sell
        int Sell = price[ind] + rec(ind + 1, trans + 1, price, k);
        int notSell = 0 + rec(ind + 1, trans, price, k);
        return max(Sell, notSell);
    }
}

int mem(int ind, int trans, vector<int> &price, int k, vector<vector<int>> &dp)
{
    int n = price.size();
    if (ind == n || trans == 2 * k)
    {
        return 0;
    }
    if (trans % 2 == 0)
    {
        // Buy
        int Buy = -price[ind] + rec(ind + 1, trans + 1, price, k);
        int notBuy = 0 + rec(ind + 1, trans, price, k);
        return max(Buy, notBuy);
    }
    else
    {
        // Sell
        int Sell = price[ind] + rec(ind + 1, trans + 1, price, k);
        int notSell = 0 + rec(ind + 1, trans, price, k);
        return max(Sell, notSell);
    }
}

int tab(vector<int> &price, int k)
{
    int n = price.size();
    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int trans = 2 * k - 1; trans >= 0; trans--)
        {
            if (trans % 2 == 0)
            {
                // Buy
                int Buy = -price[ind] + dp[ind + 1][trans + 1];
                int notBuy = 0 + dp[ind + 1][trans];
                dp[ind][trans] = max(Buy, notBuy);
            }
            else
            {
                // Sell
                int Sell = price[ind] + dp[ind + 1][trans + 1];
                int notSell = 0 + dp[ind + 1][trans];
                dp[ind][trans] = max(Sell, notSell);
            }
        }
    }
    return dp[0][0];
}

int sOpt(vector<int> &price, int k)
{
    int n = price.size();
    vector<int> curr(2 * k + 1, 0), ahead(2 * k + 1, 0);
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int trans = 2 * k - 1; trans >= 0; trans--)
        {
            if (trans % 2 == 0)
            {
                // Buy
                int Buy = -price[ind] + ahead[trans + 1];
                int notBuy = 0 + ahead[trans];
                curr[trans] = max(Buy, notBuy);
            }
            else
            {
                // Sell
                int Sell = price[ind] + ahead[trans + 1];
                int notSell = 0 + ahead[trans];
                curr[trans] = max(Sell, notSell);
            }
        }
        ahead = curr;
    }
    return ahead[0];
}
int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int k = 2, n = prices.size();
    cout << rec(0, 0, prices, k) << endl;

    vector<vector<int>> dp(n, vector<int>(2 * k, -1));
    cout << mem(0, 0, prices, k, dp) << endl;
    cout << tab(prices, k) << endl;
    cout << sOpt(prices, k) << endl;
    return 0;
}
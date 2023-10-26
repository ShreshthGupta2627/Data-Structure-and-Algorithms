// Best time to bye and sell the stocks with cooldown
/*We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:
We can buy and sell the stock any number of times.
In order to sell the stock, we need to first buy it on the same or any previous day.
We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any previously bought stock.
We can’t buy a stock on the very next day of selling it. This is the cooldown clause.*/

// Cool down means cant bye right after sell

#include <bits/stdc++.h>
using namespace std;
int rec(int ind, int buy_flag, vector<int> &prices)
{
    if (ind >= prices.size())
        return 0;
    if (buy_flag)
    {
        // Cap changes only when trade is complete i.e on sell
        int Buy = -prices[ind] + rec(ind + 1, 0, prices);
        int notBuy = 0 + rec(ind + 1, 1, prices);
        return max(Buy, notBuy);
    }
    else
    {
        // The ind + 1 will be blocked for cool down purpose :. on completing sell we move to ind + 2 instead of ind + 1
        int Sell = prices[ind] + rec(ind + 2, 1, prices);
        int notSell = 0 + rec(ind + 1, 0, prices);
        return max(Sell, notSell);
    }
    return 0;
}

int mem(int ind, int buy_flag, vector<int> &prices, vector<vector<int>> &dp)
{
    if (ind >= prices.size())
        return 0;
    if (dp[ind][buy_flag] != -1)
        return dp[ind][buy_flag];
    if (buy_flag)
    {
        int Buy = -prices[ind] + rec(ind + 1, 0, prices);
        int notBuy = 0 + rec(ind + 1, 1, prices);
        return dp[ind][buy_flag] = max(Buy, notBuy);
    }
    else
    {
        int Sell = prices[ind] + rec(ind + 2, 1, prices);
        int notSell = 0 + rec(ind + 1, 0, prices);
        return dp[ind][buy_flag] = max(Sell, notSell);
    }
    return 0;
}

int tab(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, 0));
    // Base cases are zero no need
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            if (buy)
            {
                int Buy = -prices[ind] + dp[ind + 1][0];
                int notBuy = 0 + dp[ind + 1][1];
                dp[ind][buy] = max(Buy, notBuy);
            }
            else
            {
                int Sell = prices[ind] + dp[ind + 2][1];
                int notSell = 0 + dp[ind + 1][0];
                dp[ind][buy] = max(Sell, notSell);
            }
        }
    }
    return dp[0][1];
}

int sOpt(vector<int> &prices)
{
    int n = prices.size();
    vector<int> front2(2, 0), front1(2, 0), curr(2, 0);
    for (int ind = n - 1; ind >= 0; ind--)
    {
        // Instead of loop for buy flag we can write as
        int Buy = -prices[ind] + front1[0];
        int notBuy = 0 + front1[1];
        curr[1] = max(Buy, notBuy);

        int Sell = prices[ind] + front2[1];
        int notSell = 0 + front1[0];
        curr[0] = max(Sell, notSell);
        front2 = front1;
        front1 = curr;
    }
    return front1[1];
}

int main()
{
    vector<int> price = {4, 9, 0, 4, 10};
    int n = price.size();
    cout << rec(0, 1, price) << endl;

    vector<vector<int>> dp(n, vector<int>(2, -1));
    cout << mem(0, 1, price, dp) << endl;

    cout << tab(price) << endl;

    cout << sOpt(price) << endl;
    return 0;
}
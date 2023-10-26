// Best time to sell stocks 3

/*We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:
1. We can buy and sell the stock any number of times.
2. In order to sell the stock, we need to first buy it on the same or any previous day.
3. We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we
   can’t sell before buying and can’t buy before selling any previously bought stock.
4. We can do at most 2 transactions.*/

#include <bits/stdc++.h>
using namespace std;
// We need to adjuct the capacity to 2 in previous question
int rec(int ind, int buy_flag, int cap, vector<int> &prices)
{
    if (cap == 0 || ind == prices.size())
        return 0;
    if (buy_flag)
    {
        // Cap changes only when trade is complete i.e on sell
        int Buy = -prices[ind] + rec(ind + 1, 0, cap, prices);
        int notBuy = 0 + rec(ind + 1, 1, cap, prices);
        return max(Buy, notBuy);
    }
    else
    {
        int Sell = prices[ind] + rec(ind + 1, 1, cap - 1, prices);
        int notSell = 0 + rec(ind + 1, 0, cap, prices);
        return max(Sell, notSell);
    }
    return 0;
}

int mem(int ind, int buy_flag, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp)
{
    if (cap == 0 || ind == prices.size())
        return 0;
    if (dp[ind][buy_flag][cap] != -1)
        return dp[ind][buy_flag][cap];
    if (buy_flag)
    {
        // Cap changes only when trade is complete i.e on sell
        int Buy = -prices[ind] + rec(ind + 1, 0, cap, prices);
        int notBuy = 0 + rec(ind + 1, 1, cap, prices);
        return dp[ind][buy_flag][cap] = max(Buy, notBuy);
    }
    else
    {
        int Sell = prices[ind] + rec(ind + 1, 1, cap - 1, prices);
        int notSell = 0 + rec(ind + 1, 0, cap, prices);
        return dp[ind][buy_flag][cap] = max(Sell, notSell);
    }
    return 0;
}

int tab(vector<int> &price)
{

    int n = price.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(2 + 1, 0)));
    for (int ind = 0; ind <= n; ind++)
    {
        for (int buy_flag = 0; buy_flag <= 1; buy_flag++)
        {
            dp[ind][buy_flag][0] = 0;
        }
    }
    for (int buy_flag = 0; buy_flag <= 1; buy_flag++)
    {
        for (int cap = 0; cap <= 2; cap++)
        {
            dp[n][buy_flag][cap] = 0;
        }
    }

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 0; cap <= 2; cap++)
            {
                if (buy)
                {
                    int Buy = -price[ind] + dp[ind + 1][0][cap];
                    int notBuy = 0 + dp[ind + 1][1][cap];
                    dp[ind][buy][cap] = max(Buy, notBuy);
                }
                else
                {
                    int Sell = price[ind] + dp[ind + 1][1][cap - 1];
                    int notSell = 0 + dp[ind + 1][0][cap];
                    dp[ind][buy][cap] = max(Sell, notSell);
                }
            }
        }
    }
    return dp[0][1][2];
}

int sOpt(vector<int> &price)
{
    int n = price.size();
    vector<vector<int>> ahead(2, vector<int>(2 + 1, 0)), curr(2, vector<int>(2 + 1, 0));
    for (int ind = 0; ind < n; ind++)
    {
        for (int buy_flag = 0; buy_flag <= 1; buy_flag++)
        {
            ahead[buy_flag][0] = 0;
        }
    }
    for (int buy_flag = 0; buy_flag <= 1; buy_flag++)
    {
        for (int cap = 0; cap <= 2; cap++)
        {
            ahead[buy_flag][cap] = 0;
        }
    }

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 0; cap <= 2; cap++)
            {
                if (buy)
                {
                    int Buy = -price[ind] + ahead[0][cap];
                    int notBuy = 0 + ahead[1][cap];
                    curr[buy][cap] = max(Buy, notBuy);
                }
                else
                {
                    int Sell = price[ind] + ahead[1][cap - 1];
                    int notSell = 0 + ahead[0][cap];
                    curr[buy][cap] = max(Sell, notSell);
                }
            }
        }
        ahead = curr;
    }
    return ahead[1][2];
}

// B S B S => 0 1 2 3  odd / even => buy / sell
int met2(int ind, int transection, vector<int> &price)
{
    int n = price.size();
    if (ind == n || transection == 4)
    {
        return 0;
    }
    if (transection % 2 == 0)
    {
        // Buy
        int Buy = -price[ind] + met2(ind + 1, transection + 1, price);
        int notBuy = 0 + met2(ind + 1, transection, price);
        return max(Buy, notBuy);
    }
    else
    {
        // Sell
        int Sell = price[ind] + met2(ind + 1, transection + 1, price);
        int notSell = 0 + met2(ind + 1, transection, price);
        return max(Sell, notSell);
    }
}
int main()
{
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();

    cout << rec(0, 1, 2, prices) << endl;

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2 + 1, -1)));
    cout << mem(0, 1, 2, prices, dp) << endl;

    cout << tab(prices) << endl;

    cout << sOpt(prices) << endl;

    cout << met2(0, 0, prices) << endl;
    return 0;
}
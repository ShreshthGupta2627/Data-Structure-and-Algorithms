// Best time to bye and sell stocks
/* We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:
We can buy and sell the stock any number of times.
In order to sell the stock, we need to first buy it on the same or any aheadious day.
We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any aheadiously bought stock.
*/
#include <bits/stdc++.h>
using namespace std;
int rec(int idx, int buy_flag, vector<int> &price)
{
    if (idx == price.size())
        return 0;
    // let if buy flag == 1 then i can buy the stock
    int profit = 0;
    if (buy_flag)
    {
        // Since we are buying we have to pay  :. -value of stock on that day also since we buy today i cant buy now :. buy_flag = 0
        int Pick = -price[idx] + rec(idx + 1, 0, price);
        // If i dont buy on this day
        int notPick = 0 + rec(idx + 1, 1, price);
        profit = max(Pick, notPick);
    }
    else
    {
        // since i sell today i can buy tommorow
        int Sell = price[idx] + rec(idx + 1, 1, price);
        int notSell = 0 + rec(idx + 1, 0, price);
        profit = max(Sell, notSell);
    }
    return profit;
}

int mem(int idx, int buy_flag, vector<int> &price, vector<vector<int>> &dp)
{
    if (idx == price.size())
        return 0;
    if (dp[idx][buy_flag] != -1)
        return dp[idx][buy_flag];
    int profit = 0;
    if (buy_flag)
    {
        int Pick = -price[idx] + rec(idx + 1, 0, price);
        int notPick = 0 + rec(idx + 1, 1, price);
        profit = dp[idx][buy_flag] = max(Pick, notPick);
    }
    else
    {
        int Sell = price[idx] + rec(idx + 1, 1, price);
        int notSell = 0 + rec(idx + 1, 0, price);
        profit = dp[idx][buy_flag] = max(Sell, notSell);
    }
    return profit;
}

int tab(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    dp[n][0] = dp[n][1] = 0;
    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            if (buy)
            {
                int Pick = -prices[idx] + dp[idx + 1][0];
                int notPick = 0 + dp[idx + 1][1];
                dp[idx][buy] = max(Pick, notPick);
            }
            else
            {
                int Sell = prices[idx] + dp[idx + 1][1];
                int notSell = 0 + dp[idx + 1][0];
                dp[idx][buy] = max(Sell, notSell);
            }
        }
    }
    return dp[0][1];
}

int sOpt(vector<int> &prices)
{
    int n = prices.size();
    vector<int> curr(2, 0), ahead(2, 0);
    ahead[0] = ahead[1] = 0;
    for (int idx = n - 1; idx >= 0; idx--)
    {
        for (int buy = 0; buy < 2; buy++)
        {
            if (buy)
            {
                int Pick = -prices[idx] + ahead[0];
                int notPick = 0 + ahead[1];
                curr[buy] = max(Pick, notPick);
            }
            else
            {
                int Sell = prices[idx] + ahead[1];
                int notSell = 0 + ahead[0];
                curr[buy] = max(Sell, notSell);
            }
        }
        ahead = curr;
    }
    return ahead[1];
}

int var(vector<int> &prices)
{
    int n = prices.size();
    int aheadNotBuy, aheadBuy, currBuy, currNotBuy;
    aheadNotBuy = aheadBuy = 0;
    for (int idx = n - 1; idx >= 0; idx--)
    {
        currNotBuy = max((prices[idx] + aheadBuy), (0 + aheadNotBuy));
        currBuy = max((-prices[idx] + aheadNotBuy), (0 + aheadBuy));

        aheadBuy = currBuy;
        aheadNotBuy = currNotBuy;
    }
    return aheadBuy;
}
int main()
{
    vector<int> price = {7, 1, 5, 3, 6, 4};
    cout << rec(0, 1, price) << endl;

    vector<vector<int>> dp(price.size(), vector<int>(2, -1));
    cout << mem(0, 1, price, dp) << endl;

    cout << tab(price) << endl;

    cout << sOpt(price) << endl;

    cout << var(price) << endl;
    return 0;
}
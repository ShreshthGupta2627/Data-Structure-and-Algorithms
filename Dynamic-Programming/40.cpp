/*We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:
We can buy and sell the stock any number of times.
In order to sell the stock, we need to first buy it on the same or any previous day.
We can’t buy a stock again after buying it once. In other words, we first buy a stock and then sell it. After selling we can buy and sell again. But we can’t sell before buying and can’t buy before selling any previously bought stock.
After every transaction, there is a transaction fee (‘fee’) associated with it.*/
#include <bits/stdc++.h>
using namespace std;

// Can be done in two ways :-
// 1. pay upfront
// 2. pay on completion

//  If i pay on completin
int rec1(int idx, int buy_flag, vector<int> &price, int fee)
{
    if (idx == price.size())
        return 0;
    int profit = 0;
    if (buy_flag)
    {
        int Pick = -price[idx] + rec1(idx + 1, 0, price, fee);
        int notPick = 0 + rec1(idx + 1, 1, price, fee);
        profit = max(Pick, notPick);
    }
    else
    {
        int Sell = price[idx] - fee + rec1(idx + 1, 1, price, fee);
        int notSell = 0 + rec1(idx + 1, 0, price, fee);
        profit = max(Sell, notSell);
    }
    return profit;
}

// If i pay upfront
int rec2(int idx, int buy_flag, vector<int> &price, int fee)
{
    if (idx == price.size())
        return 0;
    int profit = 0;
    if (buy_flag)
    {
        int Pick = -price[idx] - fee + rec2(idx + 1, 0, price, fee);
        int notPick = 0 + rec2(idx + 1, 1, price, fee);
        profit = max(Pick, notPick);
    }
    else
    {
        int Sell = price[idx] + rec2(idx + 1, 1, price, fee);
        int notSell = 0 + rec2(idx + 1, 0, price, fee);
        profit = max(Sell, notSell);
    }
    return profit;
}
int main()
{
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int n = prices.size(), fee = 2;
    cout << rec1(0, 1, prices, fee) << endl;

    cout << rec2(0, 1, prices, fee) << endl;
    return 0;
}
// Stock Buy and Sell
/* We are given an array Arr[] of length n. It represents the price of a stock on ‘n’ days. The following guidelines need to be followed:
We can buy and sell a stock only once.
We can buy and sell the stock on any day but to sell the stock, we need to first buy it on the same or any previous day.
We need to tell the maximum profit one can get by buying and selling this stock */

#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &price)
{
    int minn = price[0], profit = 0, maxProfit = 0;
    for (int i = 1; i < price.size(); i++)
    {
        profit = price[i] - minn;
        maxProfit = max(maxProfit, profit);
        minn = min(minn, price[i]);
    }
    return maxProfit;
}
int main()
{
    vector<int> price = {7, 1, 5, 3, 6, 4};
    cout << solve(price) << endl;
    return 0;
}
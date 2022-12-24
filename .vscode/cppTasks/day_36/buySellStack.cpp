#include <bits/stdc++.h>
using namespace std;
// Best Time to Buy and Sell Stock with Cooldown
class Solution
{
public:
    int result = 0;
    int giveme(int i, bool flg, vector<int> &prices, vector<vector<int>> &dp)
    {
        int n = prices.size();
        if (i >= n)
            return 0;
        if (dp[flg][i] != -1)
            return dp[flg][i];
        if (flg)
        {
            int sell = prices[i] + giveme(i + 2, false, prices, dp); //+2 bcz after sell  one day cool as mentioned in problem
            int notsell = giveme(i + 1, true, prices, dp);
            result = max(sell, notsell);
        }
        else
        {
            int buy = (0 - prices[i]) + giveme(i + 1, true, prices, dp);
            int notbuy = 0 + giveme(i + 1, false, prices, dp);
            result = max(buy, notbuy);
        }

        return dp[flg][i] = result;
    }

    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(2, vector<int>(prices.size(), -1));
        return giveme(0, false, prices, dp);
    }

    int maxProfit2(vector<int> &prices)
    {
        int buy /*buy[i]*/, buyPre = INT_MIN /*buy[i-1]*/;
        int sell = 0 /*sell[i]*/, sellPre1 = 0 /*sell[i-1]*/, sellPre2 = 0 /*sell[i-2]*/;

        for (int p : prices)
        {
            // transfer equations
            buy = max(buyPre, sellPre2 - p);
            sell = max(sellPre1, buyPre + p);

            // update for next iteration
            buyPre = buy;
            sellPre2 = sellPre1;
            sellPre1 = sell;
        }

        return sell;
    }
};

int main()
{
    vector<int> prices = {1, 2, 3, 0, 2};
    Solution obj;
    cout << obj.maxProfit(prices);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
int maxprofit(int arr[0], int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (int rod = 1; rod <= n; rod++)
    {
        int profit = 0;
        vector<int> c;
        for (int cut = 0; cut < rod; cut++)
        {
            profit = max(profit, arr[cut - 1] + arr[rod - cut]);
            c.push_back(profit);
        }
        ans.push_back(c);
        dp[rod] = profit;
    }
    return dp[n];
}
int main()
{
    int rod[] = {1, 3, 2, 6, 4, 8, 16, 15, 20, 18, 17};
    int n = sizeof(rod) / sizeof(int);
    cout << maxprofit(rod, n);
    for (int i = 0; i < n; i++)
    {
        for (int x : ans[i])
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int go(int index, int RemWeight, vector<pair<int, int>> &item)
{
    int n = item.size();
    if (index == n || RemWeight <= 0)
    {
        return 0;
    }
    int curWeight = item[index].first;
    int curProfit = item[index].second;
    if (curWeight > RemWeight)
    {
        return 0;
    }

    if (dp[index][RemWeight] != -1)
    {
        return dp[index][RemWeight];
    }
    int NotInclude = go(index + 1, RemWeight, item);
    int Include = curProfit + go(index + 1, RemWeight - curWeight, item);
    return dp[index][RemWeight] = max(NotInclude, Include);
}

int main()
{
    int n, wt;
    cin >> n >> wt;

    vector<pair<int, int>> item;

    for (int i = 0; i < n; i++)
    {
        int weight, profit;
        cin >> weight >> profit;
        item.push_back({weight, profit});
    }
    sort(item.begin(), item.end());
    memset(dp, -1, sizeof(dp));
    // int Rwt = 11;
    cout << go(0, wt, item) << "\n";
    return 0;
}
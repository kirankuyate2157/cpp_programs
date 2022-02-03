
#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int knapsack(int index, int k, vector<pair<int, int>> &item)
{
    int n = item.size();
    if (k <= 0 || index == n)
        return 0;

    int weight = item[index].first;
    int profit = item[index].second;
    if (k < weight)
        return dp[index][k]= knapsack(index + 1, k, item);
    if (dp[index][k] != -1)
        return dp[index][k];
    int notInclude = knapsack(index + 1, k, item);
    int include = profit + knapsack(index + 1, k - weight, item);

    return dp[index][k] = max(notInclude, include);
}


int main()
{
    int n, K;
    cin >> n >> K;
    dp[n + 1][K + 1];
    memset(dp, -1, sizeof(dp));
    vector<pair<int, int>> item;
    for (int i = 0; i < n; i++)
    {
        int w, v;
        cin >> w >> v;
        item.push_back({w, v});
    }
    cout << knapsack(0, K, item);
    //     vector<int> v, w;
    //     for (int i = 0; i < n; i++)
    //     {
    //         int ele;
    //         cin >> ele;
    //         w.push_back(ele);
    //     }
    //     for (int i = 0; i < n; i++)
    //     {
    //         int ele;
    //         cin >> ele;
    //         v.push_back(ele);
    //     }
    //  for (int i = 0; i < n; i++){
    //      cout<<w[i]<<" "<<v[i]<<"\n";
    //  }
    return 0;
}
/*
5 11
1 1
2 6
5 18
6 22
7 28
output-> 40
*/
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> dp;
    int solve(int i, int k, vector<vector<int>> &events)
    {
        if (i >= events.size() || k == 0)
            return 0;
        if (dp[i][k] != -1)
            return dp[i][k];
        int skip = solve(i + 1, k, events);
        int val = events[i][2];
        int j = i + 1;
        for (j = i + 1; j < events.size(); j++)
        {
            if (events[i][1] < events[j][0])
            {
                break;
            }
        }
        int pick = val + solve(j, k - 1, events);
        return dp[i][k] = max(skip, pick);
    }
    int maxValue(vector<vector<int>> &events, int k)
    {
        sort(begin(events), end(events));
        dp.resize(events.size() + 1, vector<int>(k + 1, -1));
        return solve(0, k, events);
    }
};

int main()
{
    vector<vector<int>> events = {{1, 2, 4}, {3, 4, 3}, {2, 3, 10}};
    int k = 2;
    Solution obj;
    cout << "maximum sum of values that you can receive by attending events : " << obj.maxValue(events, k) << endl;

    return 0;
}
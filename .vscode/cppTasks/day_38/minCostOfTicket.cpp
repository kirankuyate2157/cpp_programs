#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        int dp[366] = {0};
        unordered_set<int> travD;

        for (int day : days)
        {
            travD.insert(day);
        }

        for (int i = 1; i <= 365; i++)
        {
            if (travD.find(i) == travD.end())
                dp[i] = dp[i - 1];
            else
                dp[i] = min(dp[i - 1] + costs[0], min(dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]));
        }
        return dp[365];
    }
};

int main()
{
    vector<int> days = {1, 4, 6, 7, 8, 20}, costs = {2, 7, 15};
    Solution obj;
    cout << "  minimum number of dollars you need to travel every day in the given list of days. : \n"
         << obj.mincostTickets(days, costs) << endl;

    return 0;
}
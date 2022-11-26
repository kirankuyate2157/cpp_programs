#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int jobScheduling1(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
    {
        int n = startTime.size();
        vector<vector<int>> jobs;

        for (int i = 0; i < n; ++i)
        {
            jobs.push_back({endTime[i], startTime[i], profit[i]});
        }

        sort(jobs.begin(), jobs.end());

        map<int, int> dp = {{0, 0}};

        for (auto &job : jobs)
        {
            int cur = prev(dp.upper_bound(job[1]))->second + job[2];
            if (cur > dp.rbegin()->second)
                dp[job[0]] = cur;
        }

        return dp.rbegin()->second;
    }

    int jobShedule(vector<int> &start, vector<int> &end, vector<int> &profit)
    {
        int n = start.size();
        vector<vector<int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({end[i], start[i], profit[i]});
        }
        sort(v.begin(), v.end());
        vector<int> dp(n);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            dp[i] = v[i][2];
            if (i == 0)
            {
                ans = max(ans, dp[i]);
                continue;
            }
            dp[i] = max(dp[i], dp[i - 1]);
            int let = v[i][1];
            for (int j = i - 1; j >= 0; j--)
            {
                if (v[j][0] <= let)
                {
                    dp[i] = max(dp[i], dp[j] + v[i][2]);
                    break;
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
int main()
{
    vector<int> start = {1, 2, 3, 3};
    vector<int> end = {3, 4, 5, 6};
    vector<int> profit = {50, 10, 40, 70};
    Solution obj;
    cout << "maximum profite jobSheduling is :" << obj.jobShedule(start, end, profit);
    return 0;
}
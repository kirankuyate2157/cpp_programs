#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1), cnt(n, 1);
        int ans = 1;
        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (nums[prev] < nums[i] && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    cnt[i] = cnt[prev];
                }
                else if (nums[prev] < nums[i] && 1 + dp[prev] == dp[i])
                {
                    cnt[i] += cnt[prev];
                }
            }
            ans = max(ans, dp[i]);
        }

        int nos = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == ans)
                nos += cnt[i];
            // cout << dp[i] << ",";
        }
        return nos;
    }
};
int main()
{
    Solution obj;
    vector<int> nums = {1, 3, 5, 3, 2, 4, 7};
    cout << "LIS of give array is : " << obj.findNumberOfLIS(nums) << endl;

    return 0;
}
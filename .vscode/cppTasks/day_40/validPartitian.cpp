#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int n;
    vector<int> dp;
    bool solve(int i, vector<int> &nums)
    {

        if (i >= n)
            return true;
        bool res = false;
        if (dp[i] != -1)
            return dp[i];
        if (i + 1 < n && nums[i] == nums[i + 1])
        {
            res |= solve(i + 2, nums);
        }

        if (i + 2 < n && nums[i] == nums[i + 1] && nums[i + 1] == nums[i + 2])
        {
            res |= solve(i + 3, nums);
        }

        if (i + 2 < n && nums[i + 1] - nums[i] == 1 && nums[i + 2] - nums[i + 1] == 1)
        {
            res |= solve(i + 3, nums);
        }
        return dp[i] = res;
    }
    bool validPartition(vector<int> &nums)
    {
        n = nums.size();
        dp.resize(n + 1, -1);
        return solve(0, nums);
    }
};
int main()
{
    vector<int> nums = {4, 4, 4, 5, 6};
    Solution obj;
    cout << "Is showing Valid Partition : " << obj.validPartition(nums);
    return 0;
}
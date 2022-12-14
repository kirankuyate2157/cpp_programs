#include <bits/stdc++.h>
using namespace std;
class Solution
{

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (!n)
            return 0;
        //    vector<int>dp(n,-1);
        //    vector<int>dp2(n,-1);
        //    int ans=0;
        if (n == 1)
            return nums[0];
        //     ans=max(ans,givemax(nums,0,n-1,dp));
        //     ans=max(ans,givemax(nums,1,n,dp2));
        // return ans;
        return max(it(nums, 0, n - 1), it(nums, 1, n));
    }
    int it(vector<int> arr, int i, int n)
    {
        int ans1 = 0, ans2 = 0;
        for (; i < n; i++)
        {
            int newrob = max(ans2, ans1 + arr[i]);
            ans1 = ans2;
            ans2 = newrob;
        }
        return ans2;
    }
    int givemax(vector<int> &nums, int i, int n, vector<int> &dp)
    {
        if (i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];

        int temp = nums[i] + givemax(nums, i + 2, n, dp);
        temp = max(temp, givemax(nums, i + 1, n, dp));

        return dp[i] = temp;
    }
};

int main()
{
    vector<int> house = {4, 7, 12, 34, 88, 12, 5, 10, 100, 101};
    Solution obj;
    cout << "robing amaount will be :" << obj.rob(house) << endl;

    return 0;
}
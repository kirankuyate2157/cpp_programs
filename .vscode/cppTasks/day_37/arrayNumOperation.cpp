#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minIncrementForUnique(vector<int> &nums)
    {
        int n = nums.size();
        int ans = 0;
        int k = 0;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] >= nums[i])
            {
                ans += nums[i - 1] - nums[i] + 1;
                nums[i] = nums[i - 1] + 1;
            }
        }
        return ans;
    }
    int minDeletionSize(vector<string> &strs)
    {
        int n = strs.size();
        int m = strs[0].length();
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            char x = strs[0][i];
            for (int j = 0; j < n; j++)
            {
                if (x > strs[j][i])
                {
                    ans++;
                    break;
                    // cout<<"#";
                }
                // cout<<x<<" --- "<<strs[j][i]<<" \n";
                x = strs[j][i];
            }
            //    cout<<" @";
        }
        return ans;
    }
};

int main()
{
    vector<string> words = {"cba", "daf", "ghi"};
    vector<int> nums = {3, 2, 1, 2, 1, 7};
    Solution obj;
    cout << "Well arranged Sorted Grid with defected columns are : " << obj.minDeletionSize(words) << "\n";
    cout << "Minimum Moves required to create Unique elements  are : " << obj.minIncrementForUnique(nums) << "\n";

    return 0;
}
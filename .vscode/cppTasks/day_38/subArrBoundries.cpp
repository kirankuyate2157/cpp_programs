#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {

        int n = nums.size();
        int l = -1, r = -1, badB = -1;
        long long cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > maxK || nums[i] < minK)
            {
                badB = i;
            }
            if (nums[i] == minK)
                l = i;
            if (nums[i] == maxK)
                r = i;
            cnt += max(0, min(l, r) - badB);
        }
        return cnt;
    }
};
int main()
{
    vector<int> nums = {1, 1, 1, 1};
    Solution obj;
    cout << "number of subArray satisfy Bond limit : " << obj.countSubarrays(nums, 1, 1) << endl;
    return 0;
}
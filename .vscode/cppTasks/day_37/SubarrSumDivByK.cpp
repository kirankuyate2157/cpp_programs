#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int subarraysDivByK(vector<int> &nums, int k)
    {
        int count = 0, sum = 0;
        unordered_map<int, int> m{{0, 1}};
        for (int num : nums)
        {
            sum = (sum + num) % k;
            if (sum < 0)
                sum += k;
            count += m[sum]++;
        }
        return count;
    }
};
int main()
{
    int k = 5;
    vector<int> nums = {4, 5, 0, -2, -3, 1};
    Solution obj;
    cout << " subarrays that have a sum divisible by k : " << obj.subarraysDivByK(nums, k);
    return 0;
}
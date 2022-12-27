#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size(), x = 0;

        for (int i = 0; x >= i && x < n; i++)
        {
            if (i + nums[i] > x)
                x = i + nums[i];
        }
        return x >= n - 1;
    }
};
int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    Solution obj;
    cout << "Is possible to reach end form give steps : " << obj.canJump(nums) << endl;
    return 0;
}
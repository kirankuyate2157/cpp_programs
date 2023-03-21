#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long res = 0, sub = 0;
        for (auto x : nums)
        {
            if (x == 0)
            {
                res += ++sub;
            }
            else
            {
                sub = 0;
            }
        }
        return res;
    }
};
int main()
{
    vector<int> nums = {1, 3, 0, 0, 2, 0, 0, 4};
    Solution obj;
    cout << " Ans : " << obj.zeroFilledSubarray(nums) << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        int fast = 0, temp = 0;
        int jump = 0;
        for (int i = 0; i < n - 1; i++)
        {
            fast = max(fast, nums[i] + i);
            if (i == temp)
            {
                temp = fast;
                jump++;
            }
        }
        return jump;
    }
};
int main()
{
    vector<int> num = {2, 3, 1, 1, 4};
    Solution obj;
    cout << "minimum number of jumps to reach nums[n - 1] : " << obj.jump(num);

    return 0;
}
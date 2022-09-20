#include <bits/stdc++.h>
using namespace std;

int findLength(vector<int> &nums1, vector<int> &nums2)
{
    if (nums1.size() < nums2.size())
        swap(nums1, nums2);
    int M = nums1.size(), N = nums2.size();
    vector<int> dp(N + 1, 0);
    int ans = 0;

    for (int i = 0; i < M; i++)
    {
        for (int j = N - 1; j >= 0; j--)
        {

            if (nums1[i] == nums2[j])
            {
                dp[j + 1] = 1 + dp[j];
            }
            else
            {
                dp[j + 1] = 0;
            }

            ans = max(ans, dp[j + 1]);
        }
    }

    return ans;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 2, 1};
    vector<int> nums2 = {3, 2, 1, 4, 7};

    cout << findLength(nums1, nums2) << endl;
    return 0;
}
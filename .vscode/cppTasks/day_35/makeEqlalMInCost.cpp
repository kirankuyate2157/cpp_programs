#include <bits/stdc++.h>
#define ll long long
using namespace std;

class Solution
{
public:
    ll paisa(ll m, vector<int> &nums, vector<int> &cost)
    {
        ll kitna = 0, n = nums.size();
        for (int i = 0; i < n; i++)
        {
            kitna += (ll)(cost[i] * (abs(nums[i] - m)));
        }
        return kitna;
    }
    long long minCost(vector<int> &nums, vector<int> &cost)
    {
        ll l = *min_element(nums.begin(), nums.end());
        ll h = *max_element(nums.begin(), nums.end());
        while (l < h)
        {
            ll mid = (l + h) / 2;
            ll a = paisa(mid, nums, cost);
            ll b = paisa(mid + 1, nums, cost);
            if (a > b)
            {
                l = mid + 1;
            }
            else
            {
                h = mid;
            }
        }
        return paisa(l, nums, cost);
    }
};

int main()
{

    vector<int> nums = {1, 3, 5, 2};
    vector<int> cost = {2, 3, 1, 14};
    Solution obj;
    cout << "minimum cost will be required for getting equal arr : " << obj.minCost(nums, cost) << endl;

    return 0;
}
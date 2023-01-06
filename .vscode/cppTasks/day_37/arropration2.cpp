#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Solution
{
public:
    int maxIceCream(vector<int> &costs, int coins)
    {
        int n = costs.size();
        sort(costs.begin(), costs.end());
        int k = 0;

        for (int i = 0; i < n; i++)
        {

            if (costs[i] <= coins)
            {
                coins -= costs[i];
                k++;
                // cout << costs[i] << " ";
            }
        }
        return k;
    }

    vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2)
    {
        map<int, int> mp;
        for (auto x : items1)
        {
            mp[x[0]] += x[1];
        }
        for (auto x : items2)
        {
            mp[x[0]] += x[1];
        }
        vector<vector<int>> arr;
        for (auto x : mp)
        {
            // cout << x.first << " " << x.second << "\n";
            arr.push_back({x.first, x.second});
        }
        return arr;
    }

    long long countBadPairs(vector<int> &nums)
    {
        ll n = nums.size();
        map<ll, ll> mp;
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += i - mp[nums[i] - i];
            mp[nums[i] - i]++;
        }
        return ans;
    }
};

int main()
{
    vector<int> costs = {1, 3, 2, 4, 1};
    int coins = 7;
    vector<vector<int>> items1 = {{1, 1}, {4, 5}, {3, 8}}, items2 = {{3, 1}, {1, 5}};
    vector<int> nums = {4, 1, 3, 3};
    Solution obj;

    cout << "Maximum number of ice cream bars the boy can buy with coins coins : " << obj.maxIceCream(costs, coins) << endl;
    cout << " sum of weights of all items with value : \n [ ";
    vector<vector<int>> ans = obj.mergeSimilarItems(items1, items2);
    for (auto x : ans)
    {
        cout << "[" << x[0] << " " << x[1] << "}, ";
    }
    cout << "]\n";
    cout << "The total number of bad pairs in nums : " << obj.countBadPairs(nums) << endl;
    return 0;
}
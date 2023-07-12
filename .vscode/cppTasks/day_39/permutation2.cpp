#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> perm = nums;
        set<vector<int>> collect;
        sort(perm.begin(), perm.end());

        giveme(perm, collect, 0, nums);
        for (auto x : collect)
        {
            ans.push_back(x);
        }
        return ans;
    }
    void giveme(vector<int> perm, set<vector<int>> &collect, int idx, vector<int> &nums)
    {
        if (idx == nums.size())
        {
            collect.insert(perm);
            return;
        }
        for (int i = idx; i < perm.size(); i++)
        {
            swap(perm[i], perm[idx]);
            giveme(perm, collect, idx + 1, nums);
        }
    }
};
int main()
{
    vector<int> nums = {1, 1, 2};
    Solution obj;
    vector<vector<int>> ans = obj.permuteUnique(nums);
    for (auto x : ans)
    {
        cout << "{";
        for (auto y : x)
        {
            cout << y << ",";
        }
        cout << "}, ";
    }

    return 0;
}
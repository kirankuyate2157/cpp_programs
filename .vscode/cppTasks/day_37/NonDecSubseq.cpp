#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> findSubsequences(vector<int> &nums)
    {
        vector<int> temp;
        set<vector<int>> ans;
        giveme(nums, 0, ans, temp);
        return vector(ans.begin(), ans.end());
    }
    void giveme(vector<int> &arr, int i, set<vector<int>> &ans, vector<int> &temp)
    {
        if (i >= arr.size())
        {
            if (temp.size() > 1)
                ans.insert(temp);
            return;
        }
        if (temp.size() == 0 || temp.back() <= arr[i])
        {
            temp.push_back(arr[i]);
            giveme(arr, i + 1, ans, temp);
            temp.pop_back();
        }
        giveme(arr, i + 1, ans, temp);
    }
};

int main()
{
    vector<int> nums = {4, 6, 7, 7};
    Solution obj;
    vector<vector<int>> arr = obj.findSubsequences(nums);
    cout << " all the different possible non-decreasing subsequences of the given array with at least two elements : \n";
    cout << "{";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "{";
        for (auto x : arr[i])
        {
            cout << x << ",";
        }
        cout << "}";
    }
    cout << "}";
    return 0;
}
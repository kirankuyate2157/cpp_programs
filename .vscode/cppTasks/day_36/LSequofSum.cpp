#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        int n = queries.size();
        vector<int> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            giveme(nums, 0, queries[i], res);
        }
        return res;
    }
    void giveme(vector<int> &nums, int sum, int x, vector<int> &res)
    {
        int n = nums.size();
        int i = 0;
        for (; i < n; i++)
        {
            if (sum + nums[i] <= x)
                sum += nums[i];
            else
                break;
        }
        res.push_back(i);
    }
};

int main()
{

    vector<int> nums = {4, 5, 2, 1, 42, 21, 12, 6, 11, 98, 19}, queries = {3, 133, 44, 66, 10, 21};
    Solution obj;
    cout << "e maximum size of a subsequence of queies sum :  {";
    vector<int> res = obj.answerQueries(nums, queries);
    for (auto x : res)
        cout << x << ",";
    cout << "}";
}
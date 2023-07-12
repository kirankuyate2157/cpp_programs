#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        set<int> st;
        for (auto x : nums)
            st.insert(x);

        if (st.size() != nums.size())
            return true;
        else
            return false;
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    cout << "is contain duplicate in this list of ele are : " << obj.containsDuplicate(nums) << endl;
    return 0;
}
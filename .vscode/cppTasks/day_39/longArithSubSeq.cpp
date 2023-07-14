#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestSubsequence(vector<int> &arr, int difference)
    {
        map<int, int> m;
        int mx = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            m[arr[i]] = 1 + m[arr[i] - difference];
            mx = max(mx, m[arr[i]]);
        }
        return mx;
    }
};
int main()
{
    vector<int> arr = {1, 2, 3, 4};
    int difference = 1;
    Solution obj;
    cout << "The longest arithmetic subsequence is : " << obj.longestSubsequence(arr, difference) << endl;

} // namespace std;

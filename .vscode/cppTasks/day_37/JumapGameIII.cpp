#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    set<int> vis; // used for once to reach at that position not more that 1.
    bool canReach(vector<int> &arr, int start)
    {
        if (vis.count(start) || start < 0 || start >= arr.size())
            return false;
        if (arr[start] == 0)
            return true;
        vis.insert(start);
        return canReach(arr, start + arr[start]) || canReach(arr, start - arr[start]);
    }
};

int main()
{
    vector<int> arr = {4, 2, 3, 0, 3, 1, 2};
    int start = 5;
    Solution obj;
    cout << " can reach to any index with value 0 : " << obj.canReach(arr, start) << endl;

    return 0;
}
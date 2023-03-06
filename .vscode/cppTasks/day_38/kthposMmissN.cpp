#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        int n = arr.size();
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (arr[mid] - (mid + 1) >= k)
                r = mid - 1;
            else
                l = mid + 1;
        }
        return l + k;
    }
};
// 0 1 2 3 4 5 6 7 8 9 10
//   2 3 4 7 11
int main()
{
    vector<int> arr = {2, 3, 4, 7, 11};
    Solution obj;
    cout << "Missing Number is  : " << obj.findKthPositive(arr, 5);
    return 0;
}
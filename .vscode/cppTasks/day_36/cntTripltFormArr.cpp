#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor

class Solution
{
public:
    int countTriplets(vector<int> &arr)
    {
        // Time Complexity: O(n^2)
        // Space Complexity: O(n)

        int n(arr.size()), ans(0);
        int xors[n + 1];
        xors[0] = 0;

        for (int i = 0; i < n; ++i)
            xors[i + 1] = xors[i] ^ arr[i];

        for (int i = 0; i < n; ++i)
            for (int k = i + 1; k < n; ++k)
                // j ranges from i + 1 to k
                // we check if xors[j] ^ xors[i] == xors[k + 1] ^ xors[j]
                // property of xor: x ^ x = 0, 0 ^ x = x ^ 0 = x
                // Thus, a_i ^ ... ^ a_j = (a_1 ^ ... ^ a_(i - 1)) ^ (a_1 ^ ...^ a_(i - 1) ^ a_i ^ ... ^ a_j)
                //                       = xors[i - 1] ^ xors[j].
                // which is equivalent to xors[i] == xors[k + 1]
                // if that is true, it is true for every j, and we increment ans by k - i
                if (xors[i] == xors[k + 1])
                    ans += k - i;
        return ans;
    }
};
int main()
{

    vector<int> arr = {2, 3, 1, 6, 7};
    Solution obj;
    cout << obj.countTriplets(arr);
    return 0;
}
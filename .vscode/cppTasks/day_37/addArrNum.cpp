#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        int n = num.size();
        int i = 0;
        reverse(num.begin(), num.end());
        while (k > 0)
        {
            int x = k % 10;
            if (i < n)
                num[i] += x;
            else
                num.push_back(x);

            // cout << num[i] << " ";
            int carry = num[i] / 10;
            num[i] = num[i] % 10;
            k /= 10;
            k += carry;
            i++;
        }
        reverse(num.begin(), num.end());
        return num;
    }
};
int main()
{
    vector<int> num = {1, 2, 0, 0};
    int k = 34;
    Solution obj;
    cout << "The array-form of the integer num + k : [";
    vector<int> ans = obj.addToArrayForm(num, k);
    for (auto x : ans)
        cout << x << ",";
    cout << "]";
    return 0;
}
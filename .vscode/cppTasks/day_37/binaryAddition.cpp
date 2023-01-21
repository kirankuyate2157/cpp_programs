#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string ans = "";
        int x = 0;
        int i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0)
        {
            int sum = x;
            if (i >= 0)
                sum += a[i--] - '0';
            if (j >= 0)
                sum += b[j--] - '0';
            x = sum > 1 ? 1 : 0;
            ans += to_string(sum % 2);
        }
        if (x == 1)
            ans += to_string(x);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main()
{
    string a = "1010", b = "1011";
    Solution obj;
    cout << " sum as a binary string. : " << obj.addBinary(a, b);
    return 0;
}
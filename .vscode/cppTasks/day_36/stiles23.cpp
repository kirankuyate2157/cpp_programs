#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution
{
public:
    int numTilings(int n)
    {
        int mode = 1e9;
        mode += 7;
        vector<ll> dp(n + 4, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        if (n <= 3)
            return dp[n];

        for (int i = 4; i <= n; ++i)
        {
            dp[i] = 2 * dp[i - 1] + dp[i - 3];
            dp[i] %= mode;
        }
        return dp[n];
    }
};

int main()
{
    Solution obj;
    int n = 8;
    cout << "Possible ways of stiles we  Arrange within that " << n << "  area is :" << obj.numTilings(n) << endl;

    return 0;
}
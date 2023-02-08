#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    set<int> vis;
    bool canReach(string s, int minJump, int maxJump)
    {
        int n = s.length();
        vector<bool> dp(n, false);
        dp[0] = true;
        int k = 0;
        for (int i = 1; i < n; i++)
        {
            if (i >= minJump)
                k += dp[i - minJump];
            if (i > maxJump)
                k -= dp[i - maxJump - 1];

            dp[i] = (s[i] == '0') && (k > 0);
        }
        return dp[n - 1];
    }
};

int main()
{
    string s = "011010";
    int minJump = 2, maxJump = 3;
    Solution obj;
    cout << " can reach index s.length - 1  : " << obj.canReach(s, minJump, maxJump);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int f(string &a, string &b, int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 || j == 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];
    if (a[i - 1] == b[j - 1])
        return dp[i][j] = 1 + f(a, b, i - 1, j - 1, dp);
    return dp[i][j] = max(f(a, b, i - 1, j, dp), f(a, b, i, j - 1, dp));
}

int longestCommonSubsequence(string a, string b)
{
    int n = a.size();
    int m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    int len = dp[n][m];
    string result = "";
    for (int i = 0; i < len; i++)
        result += 'm';
    int i = n, j = m, k = len - 1;
    while (j > 0 && i > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            result[k] = a[i - 1];
            i--;
            j--;
            k--;
        }
        else if (dp[i][j - 1] > dp[i - 1][j])
        {
            j--;
        }
        else
            i--;
    }
    cout << result << "\n";
    return dp[n][m];
}

int main()
{

    string a = "abcde", b = "ace";

    int res = longestCommonSubsequence(a, b);
    cout << res << "\n";
}
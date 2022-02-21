#include <bits/stdc++.h>
using namespace std;
bool isSubsqu(string s1, string s2)
{
    int n = s1.length(), m = s2.length();
    int i = 0, j = 0;
    while (i < n || j < m)
    {
        if (s1[i] == s2[j])
        {
            cout << i << " -- " << j << "\n";
            cout << s1[i];
            i++, j++;
        }
        else
        {
            j++;
        }
    }
    if (j < m)
        return true;
    return false;
}
// memmoization approch..
int lcs(string s1, string s2, int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j])
        return dp[i][j];
    if (s1[i] == s2[j])
    {
        return dp[i][j] = 1 + lcs(s1, s2, i - 1, j - 1, dp);
    }
    else
    {
        return dp[i][j] = max(lcs(s1, s2, i - 1, j, dp), lcs(s1, s2, i, j - 1, dp));
    }
}
// optimal  approch
int lcs2(string s1, string s2, int n, int m, vector<vector<int>> &dp)
{
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {

            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            if (s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }return dp[n][m];
}
int main()
{
    string s1 = "AGTAB", s2 = "GXTXAYB";
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    // cout << lcs(s1, s2, n - 1, m - 1, dp);
    // cout << isSubsqu(s1, s2);
    cout<<lcs2(s1,s2,n,m,dp);
    cout << "\n";

    return 0;
}
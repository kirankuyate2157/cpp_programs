#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> dp;
    int giveme(int i, int j, int n, int m)
    {
        if (i == m - 1 && j == n - 1)
            return 1;
        if (i >= m || j >= n)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = giveme(i + 1, j, n, m) + giveme(i, j + 1, n, m);
    }
    int uniquePaths(int m, int n)
    {
        dp.resize(m + 1, vector<int>(n + 1, -1));
        return giveme(0, 0, n, m);
    }
};
int main()
{
    int n = 5, m = 3;
    Solution obj;
    cout << "possible paths : " << obj.uniquePaths(n, m) << endl;

    return 0;
}
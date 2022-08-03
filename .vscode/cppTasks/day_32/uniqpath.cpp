#include <bits/stdc++.h>
using namespace std;
int unique(vector<string> grid, int l, int r, int n, vector<vector<bool>> &dp)
{
    if (r > n || l > n)
    {
        return 0;
    }
    else if (l == n && r == n)
    {
        cout << "Case #";
        return 1;
    }
    else if (grid[l][r] = '1')
    {
        if (dp[l][r] == true)
        {
            return 1;
        }
        dp[l][r] = true;
        return unique(grid, l + 1, r, n, dp) + unique(grid, l, r + 1, n, dp);
    }
    else
    {
        return 0;
    }
}
int main()
{
    vector<string> grid = {"111011",
                           "111010",
                           "101111",
                           "110101",
                           "011111"};

    cout << "uniques path are : ";
    vector<vector<bool>> dp(grid.size(), vector<bool>(grid[0].size(), false));
    cout << unique(grid, 0, 0, grid.size() - 1, dp);
    return 0;
}
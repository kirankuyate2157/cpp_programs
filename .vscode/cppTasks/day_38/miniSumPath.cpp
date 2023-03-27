#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        vector<int> cur(m, grid[0][0]);

        for (int i = 1; i < m; i++)
            cur[i] = cur[i - 1] + grid[i][0];

        for (int j = 1; j < n; j++)
        {
            cur[0] += grid[0][j];
            for (int i = 1; i < m; i++)
                cur[i] = min(cur[i - 1], cur[i]) + grid[i][j];
        }
        return cur[m - 1];
    }
};
int main()
{
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    Solution obj;
    cout << "path minimizes the sum. : " << obj.minPathSum(grid);

    return 0;
}
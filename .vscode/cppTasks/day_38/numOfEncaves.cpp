#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if ((i == 0 || j == 0 || i == m - 1 || j == n - 1) && grid[i][j] == 1)
                {
                    dfs(grid, i, j);
                }
            }
        }
        int sum = accumulate(begin(grid), end(grid), 0, [](int sum, auto row)
                             { return sum + accumulate(begin(row), end(row), 0); });

        return sum;
    }

private:
    void dfs(vector<vector<int>> &grid, int i, int j)
    {
        grid[i][j] = 0;
        vector<vector<int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (vector<int> &direction : directions)
        {
            int x = i + direction[0];
            int y = j + direction[1];
            if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size() && grid[x][y] == 1)
            {
                dfs(grid, x, y);
            }
        }
    }
};

int main()
{
    vector<vector<int>> grid = {{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    Solution obj;
    cout << "number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves : " << obj.numEnclaves(grid);
    return 0;
}
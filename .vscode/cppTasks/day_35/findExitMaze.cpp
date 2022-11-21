#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &e)
    {
        queue<pair<int, int>> q;
        q.push({e[0], e[1]});

        // current moves
        int moves = 1;
        int rows = maze.size();
        int cols = maze[0].size();

        // to move in all directions
        vector<vector<int>> offsets = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        // mark the entrance  as visited
        maze[e[0]][e[1]] = '+';
        while (!q.empty())
        {
            int l = q.size();
            // for every node in the queue visit all of it's adjacent nodes which are not visited yet
            for (int k = 0; k < l; k++)
            {
                auto [i, j] = q.front();
                q.pop();

                // try all 4 directions from the current cell
                for (int l = 0; l < 4; l++)
                {
                    int x = i + offsets[l][0];
                    int y = j + offsets[l][1];
                    // a invalid move
                    if (x < 0 || y < 0 || x >= rows || y >= cols || maze[x][y] == '+')
                        continue;
                    // if we have reached the exit then current moves are the min moves to reach the exit
                    if (x == 0 || y == 0 || x == rows - 1 || y == cols - 1)
                        return moves;
                    // block the cell as we have visited
                    maze[x][y] = '+';
                    q.push({x, y});
                }
            }
            // increment the moves
            moves++;
        }
        return -1;
    }
};

void dfs(vector<vector<char>> maze, int m, int n, vector<vector<int>> &dp, vector<int> &entrance)
{
    queue<pair<int, int>> q;
    vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    q.push(make_pair(entrance[0], entrance[1]));
    int path = 0;
    while (!queue.empty())
    {
        auto person = q.top();
        q.pop();
        int i = person[0];
        int j = person[1];
        for (int k = 0; k < 4; k++)
        {
            int x = i + dir[k][0];
            int y = j + dir[k][1];

            if (maze[x][y] == '-' && i > 0 || i < n || j > 0 || j < m)
            {
                path++;
                q.push({x, y});
            }
            if ((i <= 0 || i >= n || j <= 0 || j >= m) && maze[x][y] == '+')
            {
                ans = max(ans, path);
            }
        }
    }
}

int nearestExit(vector<vector<char>> &maze, vector<int> &entrance)
{
    int n = maze.size();
    int m = maze[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    dfs(maze, n, m, dp, entrance);
    return ans;
}

int main()
{

    return 0;
}
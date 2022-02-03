#include <bits/stdc++.h>
using namespace std;
template <typename T>
void bfs(int i, int j, vector<vector<T>> &grid, vector<vector<bool>> &visited, int count)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    q.push({i, j});
    int dr[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    while (!q.empty())
    {
        int curi = q.front().first;
        int curj = q.front().second;
        q.pop();
        if (visited[curi][curj] == 1)
            continue;
        visited[curi][curj] = 1;
        grid[curi][curj] = count;
        for (int k = 0; k < 4; k++)
        {
            int dx = dr[k][0];
            int dy = dr[k][1];

            int nbri = curi + dx;
            int nbrj = curj + dy;
            if (nbri >= 0 && nbri < n && nbrj >= 0 && nbrj < m && (grid[nbri][nbrj] == 1 || grid[nbri][nbrj] == '1'))
            {
                q.push({nbri, nbrj});
            }
        }
    }
}
template <typename T>
void dfs(int i, int j, vector<vector<T>> &grid, vector<vector<bool>> &visited)
{
    int n = grid.size(), m = grid[0].size();
    if (visited[i][j])
        return;
    visited[i][j] = true;
    int dr[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int k = 0; k < 4; k++)
    {
        int xi = dr[k][0];
        int yj = dr[k][1];
        int nbri = xi + i;
        int nbrj = yj + j;
        if (nbri >= 0 && nbri < n && nbrj >= 0 && nbrj < m && (grid[nbri][nbrj] == '1' || grid[nbri][nbrj] == 1) && visited[nbri][nbrj] == false)
        {

            cout << "nbri =" << nbri << " nbrj =" << nbrj << " " << grid[nbri][nbrj] << "\n";
            dfs(nbri, nbrj, grid, visited);
        }
    }
}
template <typename T>
int numIslands(vector<vector<T>> &grid)
{
    int count = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == false && (grid[i][j] == 1 || grid[i][j] == '1'))
            {
                cout << "i = " << i << " _ j = " << j << "\n";
                cout << visited[i][j] << "--" << grid[i][j] << "\n";
                count++;
                // bfs(i, j, grid, visited, count);
                dfs(i, j, grid, visited);
            }
        }
    }
    for (int i = 0; i < visited.size(); i++)
    {
        for (int x : visited[i])
            cout << x << " ";
        cout << "\n";
    }
    return count;
}
int main()
{
    vector<vector<char>> arr = {{'1', '1', '1', '1', '0'},
                                {'1', '1', '0', '1', '0'},
                                {'1', '1', '0', '0', '0'},
                                {'0', '0', '0', '0', '0'}};

    vector<vector<char>> arr2 = {{'1', '1', '0', '0', '0'},
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '1', '0', '0'},
                                 {'0', '0', '0', '1', '1'}};

    vector<vector<int>> arr3 = {{1, 1, 0, 0, 1, 1, 0, 1, 1},
                                {1, 1, 0, 0, 1, 0, 1, 0, 0},
                                {1, 0, 0, 1, 0, 0, 0, 0, 1},
                                {0, 1, 1, 0, 0, 0, 0, 1, 1},
                                {0, 1, 1, 1, 0, 0, 1, 1, 0},
                                {1, 1, 1, 0, 0, 1, 0, 0, 1},
                                {1, 1, 0, 0, 0, 1, 0, 0, 1}};

    vector<vector<char>> arr4 = {{'1', '1', '0', '1'},
                                 {'1', '1', '0', '0'},
                                 {'1', '0', '0', '1'},
                                 {'0', '1', '1', '0'}};
    cout << numIslands(arr);
    cout << "\n";
    for (int i = 0; i < arr.size(); i++)
    {
        for (int x : arr[i])
            cout << (x) << " ";
        cout << "\n";
    }

    return 0;
}
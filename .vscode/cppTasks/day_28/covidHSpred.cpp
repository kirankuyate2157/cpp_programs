#include <bits/stdc++.h>
using namespace std;
int dr[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
int bsf(queue<pair<int, pair<int, int>>> q, vector<vector<int>> &grid, vector<vector<bool>> &visited)
{
    int n = grid.size(), m = grid[0].size();
    int level = 0;
    int z = 0;
    while (!q.empty())
    {

        int myLevel = q.front().first;
        int i = q.front().second.first;
        int j = q.front().second.second;
        q.pop();
        if (visited[i][j])
            continue;
        visited[i][j] = true;
        for (int k = 0; k < 4; k++)
        {
            // cout << "pass3" << z++ << "\n";
            int dx = dr[k][0];
            int dy = dr[k][1];
            int nbri = i + dx;
            int nbrj = j + dy;
            if (nbri >= 0 && nbri < n && nbrj >= 0 && nbrj < m)
            {
                if (grid[nbri][nbrj] == 1)
                {
                    q.push({myLevel + 1, {nbri, nbrj}});
                }
                else if (grid[nbri][nbrj] == 2)
                {
                    q.push({myLevel, {nbri, nbrj}});
                }
            }
        }
        level = max(myLevel, level);
    }
    return level;
}

int veRange(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    int count = -1;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<int, pair<int, int>>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({0, {i, j}});
                // cout<<"pass1\n";
            }
        }
    }
    count = max(count, bsf(q, grid, visited));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j] == false && grid[i][j] == 1)
            {
                // cout << "pass2\n";
                count = -1;
                break;
            }
        }
    }
    return count;
}
int main()
{
    int n, m;
    cin >> n >> m;
     vector<vector<int>> hos(n,vector<int>(m,0)) ;//= {{2, 2, 0, 0, 1, 0},
    //                            {2, 1, 0, 0, 2, 1},
    //                            {2, 1, 0, 0, 0, 1},
    //                            {0, 0, 0, 1, 2, 2}};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            hos[i][j]=x;
        }
    }
    cout << veRange(hos);
    cout << "\n";
    for (int i = 0; i < hos.size(); i++)
    {
        for (int x : hos[i])
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
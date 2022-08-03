#include <bits/stdc++.h>
using namespace std;
// unsolved    🔴
void DFS(int i, int j, int &s, vector<vector<int>> &m, vector<vector<int>> &visited, int n)
{
    int nn = m.size();
    int mm = m[0].size();
    if (i >= nn || j >= mm || i < 0 || j < 0 || m[i][j] <= -1)
        return;
    if (visited[i][j] == 1)
        return;
    if (m[i][j] == n)
    {
        s++;
        return;
    }
    visited[i][j] = 1;
    s++;
    DFS(i - 1, j, s, m, visited, n);
    DFS(i + 1, j, s, m, visited, n);
    DFS(i, j - 1, s, m, visited, n);
    DFS(i, j + 1, s, m, visited, n);
    visited[i][j] = 0;
}

int main()
{
    vector<vector<int>> arr = {{1, 0, 0}, {0, 0, 0}, {0, 0, 2}};

    int s = 0;
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    DFS(2, 2, s, arr, vis, 2);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << vis[i][j] << ", ";
        }
        cout << "\n";
    }
    cout << "\nans is : " << s;
    return 0;
}
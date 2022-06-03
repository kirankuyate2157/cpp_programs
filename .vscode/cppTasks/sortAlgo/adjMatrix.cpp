#include <iostream>
#define n 10
using namespace std;
int adj[n][n];
void dfs(int src, bool visited[])
{
    visited[src] = true;
    for (int v = 0; v < n; v++)
    {
        if (adj[src][v])
        {
            if (!visited[v])
                dfs(v, visited);
        }
    }
}
bool isConnected(int m)
{
    bool *vis = new bool[m];
    for (int u; u < m; u++)
    {
        for (int i = 0; i < m; i++)
            vis[i] = false;
        dfs(u, vis);
        for (int i = 0; i < m; i++)
        {
            if (!vis[i])
                return false;
        }
    }
    return true;
}

void makeZero()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = 0;
        }
    }
}
void display(int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int m, e;
    cin >> m >> e;
    makeZero();
    for (int i = 0; i < e; i++)
    {

        int x, y, w;
        cin >> x >> y >> w;
        adj[x][y] = w;
        adj[y][x] = w;
    }
    display(m);
    if (isConnected(m))
        cout << "The Graph is connected.";
    else
        cout << "The Graph is not connected.";
}

/*
5 5
1 2 3
2 3 4
4 5 6
2 4 5
1 0 2

0 2 0 0 0
2 0 3 0 0
0 3 0 4 5
0 0 4 0 0
0 0 5 0 0
The Graph is connected.
*/
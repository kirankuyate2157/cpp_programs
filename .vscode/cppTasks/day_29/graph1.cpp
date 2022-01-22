#include <bits/stdc++.h>
using namespace std;

void bfs(int src, vector<vector<int>> &adj, int n)
{
    queue<int> q;
    int visited[n];
    memset(visited, 0, sizeof(visited));
    q.push(src);
    visited[src] = 1;
    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        if (visited[n]) continue;
        cout << n << ",";
        visited[n] = 1;
        for (int a : adj[n])
            q.push(a);
    }
}

void dfs(int src, vector<vector<int>> &adj, int visited[])
{
    if (visited[src])
        return;
    //  cout << "\n";
    // for (int i = 0; i <= 6; i++)
    // {
    //     // cout << visited[i] << "_";
    // }
    cout <<"-"<< src << ",";
    visited[src] = 1;
    for (int a : adj[src])
    {
        dfs(a, adj, visited);
    }
}



int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int visited[n + 1];
    memset(visited, 0, sizeof(visited));
    dfs(4, adj, visited);
    bfs(4, adj, n);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void bfs(int src, vector<vector<int>> adj, int n)
{
    queue<int> q;
    int visited[n] = {0};
    // memset(visited, 0, sizeof(visited));
    q.push(src);
    // visited[src] = 1;
    // cout << "1..";
    int i = 1;
    while (!q.empty())
    {

        int n = q.front();
        q.pop();
        // cout << i++ << "... ";
        if (visited[n])
            continue;

        cout << n << ",";
        visited[n] = 1;
        for (int i = 0; i < adj.size(); i++)
        {
            if (adj[n][i] == 1)
                q.push(i);
        }
    }
}
void dfs(int src, vector<vector<int>> adj, int visited[])
{
    if (visited[src])
        return;
    cout << src << " ";
    visited[src] = 1;
    for (int i = 0; i < adj.size(); i++)
    {
        if (adj[src][i] == 1)
            dfs(i, adj, visited);
    }
}

// int main()
// {
//     int n, e;
//     cin >> n >> e;
//     vector<int> adj[n];
//     for (int i = 0; i < e; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj[u].push_back(v);
//         adj[v].push_back(u);
//     }
//     int visited[n] = {0};
//     //    dfs(3,adj,visited);
//     bfs(3, adj, n);
//     return 0;
// }

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    int visited[n + 1];
    memset(visited, 0, sizeof(visited));
    for(int i=0;i<adj.size();i++){
        cout<<i<<" : ";
        for(int j=0;j<adj.size();j++){
            cout<<adj[i][j]<<",";
        }
        cout<<"\n";
    }
    dfs(4, adj, visited);
    cout<<"\n";
    bfs(4, adj, n);

    return 0;
}
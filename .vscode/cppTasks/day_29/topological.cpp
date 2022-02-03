#include <bits/stdc++.h>
using namespace std;
void topologySort(vector<int> adj[], int degree[], int e)
{
    queue<int> q;
    for (int i = 0; i < e; i++)
    {
        if (degree[i] == 0)
        {
            q.push(i);
        }
        while (!q.empty())
        {
            int cur = q.front();
            q.pop();
            cout << cur << ",";
            for (int nbr : adj[cur])
            {
                degree[nbr]--;
                if (degree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj[n + 1];
    int visited[n + 1];
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        visited[v]++;
    }
    // for (int x : visited)
    // {
    //     cout << x << " ";
    // }
    topologySort(adj, visited, e);
    return 0;
}
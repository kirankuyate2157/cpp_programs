#include <bits/stdc++.h>
using namespace std;
#define maxN 1000
bool visited[maxN];
int disc[maxN];
int parent[maxN];
int low[maxN];
int timet = 1;
void dfs(int u, vector<int> adj[])
{
    disc[u] = low[u] = timet++;
    visited[u] = true;
    for (int v : adj[u])
    {
        if (v == parent[u])
        {
            cout << " --parented-- ";
            continue;
        }
        else if (visited[v])
        {
            cout << "  -visited- ";
            low[u] = min(low[u], disc[v]);
        }
        else
        {

            cout << "\nForward   ---> \n";

            parent[v] = u;
            cout << v << " __" << parent[v] << "(" << disc[u] << "," << low[u] << ") ,";
            dfs(v, adj);
            low[u] = min(low[u], low[v]);
            cout << "\nReverse   ---> \n";
            cout << v << " __" << parent[v] << "(" << disc[u] << "," << low[u] << ") ,";
            if (low[v] > disc[u])
            {
                cout << "Bridge is: ( " << u << "," << v << ")\n";
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    vector<int> adj[n + 1];
    for (int i = 0; i < e; i++)
    {

        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << ": ";
        for (auto x : adj[i])
            cout << x << ", ";
        cout << "\n";
    }
    for (int i = 0; i <= n; i++)
    {
        parent[i] = -1;
        disc[i] = INT_MAX;
        low[i] = INT_MAX;
        visited[i] = false;
    }
    // for (int i = 0; i < n; i++){
    //     cout<<"("<<disc[i]<<","<<low[i]<<","<<parent[i]<<") , ";
    // }
    // parent[0]=-1;
    dfs(1, adj);
    return 0;
}
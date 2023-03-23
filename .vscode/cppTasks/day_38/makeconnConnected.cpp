#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int i, vector<vector<int>> &adj, vector<bool> &vis)
    {
        vis[i] = true;
        for (auto x : adj[i])
        {
            if (!vis[x])
            {
                dfs(x, adj, vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < n - 1)
            return -1;
        vector<vector<int>> adj(n);
        for (auto x : connections)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        vector<bool> vis(n, false);
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis);
                res++;
            }
        }
        return res - 1;
    }
};

int main()
{
    int n = 6;
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}};

    Solution obj;
    cout << "Connections: " << obj.makeConnected(n, connections) << endl;

    return 0;
}
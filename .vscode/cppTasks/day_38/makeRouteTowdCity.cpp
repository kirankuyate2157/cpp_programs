#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int res = 0;
    void dfs(int i, vector<vector<int>> &adj, set<int> &vis, set<pair<int, int>> edges)
    {
        for (auto x : adj[i])
        {
            if (vis.find(x) != vis.end())
                continue;
            if (edges.find({x, i}) == edges.end())
                res += 1;
            vis.insert(x);
            dfs(x, adj, vis, edges);
        }
    }
    int dfs(vector<vector<int>> &gr, vector<bool> &visited, int from)
    {
        auto change = 0;
        visited[from] = true;
        for (auto to : gr[from])
        {
            if (!visited[abs(to)])
            {
                // cout << to << " ,";
                change += dfs(gr, visited, abs(to)) + (to > 0);
            }
        }
        return change;
    }
    int minReorder(int n, vector<vector<int>> &connections)
    {
        vector<vector<int>> adj(n);
        set<pair<int, int>> edges;
        for (auto x : connections)
        {
            edges.insert({x[0], x[1]});
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(-x[0]);
        }
        // set<int>vis;
        // vis.insert(0);
        // dfs(0,adj,vis,edges);
        // return res;
        vector<bool> vis(n, false);
        return dfs(adj, vis, 0);
    }
};
int main()
{
    vector<vector<int>> connections = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
    int n = 6;
    Solution obj;
    cout << "Connections rq to divert : " << obj.minReorder(n, connections) << endl;

    return 0;
}
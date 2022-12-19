#include <bits/stdc++.h>
using namespace std;
bool bsf(int n, unordered_map<int, vector<int>> nodes, int start, int end)
{

    vector<int> vis(n, 0);
    queue<int> q;
    q.push(start);
    vis[start] = true;
    // cout << " hee ";
    while (!q.empty())
    {
        int src = q.front();
        q.pop();
        // cout << " hee 1 ";
        vector<int> v = nodes[src];
        for (int i = 0; i < v.size(); i++)
        {
            if (vis[v[i]] == false)
            {
                // cout << " hee 3";
                q.push(v[i]);
                vis[v[i]] = true;
            }
        }
    }

    return vis[end];
}

int main()
{

    int n = 6;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
    unordered_map<int, vector<int>> nodes;
    for (auto x : edges)
    {
        vector<int> v = x;

        nodes[v[0]].push_back(v[1]);
        nodes[v[1]].push_back(v[0]);
    }

    n = nodes.size();
    cout << "is reached ? : " << bsf(n, nodes, 0, 2);
    return 0;
}
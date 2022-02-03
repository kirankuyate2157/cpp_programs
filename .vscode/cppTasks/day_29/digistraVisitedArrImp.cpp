#include <bits/stdc++.h>
using namespace std;

int getMiniDistNode(bool visited[], int dist[], int n)
{
    int mini_node = 0, mini_dist = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false && mini_dist > dist[i])
        {
            mini_dist = dist[i];
            mini_node = i;
        }
    }

    return mini_node;
}

void dijakshtra(int src, vector<pair<int, int>> adj[], int n)
{
    int dist[n];
    bool visited[n];

    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[src] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int cur = getMiniDistNode(visited, dist, n);
        visited[cur] = true;

        for (pair<int, int> p : adj[cur])
        {
            int nbr = p.first;
            int edge = p.second;

            if (visited[nbr] == false && dist[cur] + edge < dist[nbr])
            {
                dist[nbr] = dist[cur] + edge;
            }
        }
    }

    // printing the single source shortest distance..
    cout << "shortest distance from source: " << src << " is: \n";
    for (int i = 0; i < n; i++)
    {
        cout << i << ": " << dist[i] << "  , ";
    }
    cout << "\n";
}

int main()
{
    int n, e;
    cout << "Enter the number of nodes and edges in your graph:\n";
    cin >> n >> e;
    vector<pair<int, int>> adj[n];

    cout << "Enter the edges of your graph\n";
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    dijakshtra(3, adj, n);
    return 0;
}
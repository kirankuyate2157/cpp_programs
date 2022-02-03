#include <bits/stdc++.h>
using namespace std;
void Dijkstra(int src, vector<pair<int, int>> adj[], int n)
{
    int dist[n + 1]; // distance arrays from source
    for (int i = 0; i <= n; i++)
        dist[i] = INT_MAX;                                                              // initially it wa infinite
    dist[src] = 0;                                                                      // self distance is zero
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // min heap priority queue
    // pq pair is going to to be store first: min_dist to reach node that is stored in second from src
    // pair(node,weight)
    pq.push({src, dist[src]}); // source  pair
    while (!pq.empty())
    {
        pair<int, int> cur = pq.top();
        pq.pop();
        for (pair<int, int> nbr : adj[cur.first]) // finding minimun node pair for that propose...
        {
            int node = nbr.first;
            int weight = nbr.second;
            if (cur.second + weight < dist[nbr.first]) // if minimum dist is found then take it if not move  or relax it..
            {
                dist[nbr.first] = cur.second + weight; // if less then edits distance
                pq.push({node, dist[nbr.first]});      // also update in p_queue..
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        cout << i << " : " << dist[i] << "\n"; // printing  distance
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < e; i++) // edges list &and their weights
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    for (int i = 0; i <= n; i++) /// printing  adj list
    {
        cout << i << " : ";
        for (auto x : adj[i])
        {
            cout << "(" << x.first << "," << x.second << ")";
        }
        cout << "\n";
    }
    int src;
    cin >> src;
    Dijkstra(src, adj, n);
    return 0;
}

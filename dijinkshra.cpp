#include <bits/stdc++.h>

using namespace std;

void dijakshtra(int src, int n,vector<pair<int, int>> adj[])
{
    int dist[n + 1];
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});
    // pq pair is going to to be store first: min_dist to reach node that is stored in second from src
    while (!pq.empty())
    {
        pair<int.int>cur = pq.top();
        pq.pop();
        for (pair<int, int> nbrinfo : adj[cur.second])
        {
            int nbr = nbrinfo.first;
            int weight = nbrinfo.second;
            if (cur.first + weight < dist[nbr])
            {
                dist[nbr] = cur.first + weight;
                pq.push({dist[nbr], nbr});
            }
        }
    }
    for (int i = 0; i <= n; i++)
    {
        cout << i << " : " << dist[i]<< " , ";
    }
    cout << "\n";
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> adj[n + 1];
    for (int i = 0; i < e; i++)
    {
        int v, u, w;
        cin >> v >> u >> w;
        adj[v].push_back({u, w});
        adj[u].push_back({v, w});
int  src;
cin>>src;
dijakshtra(src,n,adj);
    }
    return 0;
}

// #include <stdio.h>
// #include <stdlib.h>

// int main()
// {
// char*p1="Name";
// char*p2;
// p2=(char*)malloc(20);
// printf(p2);
// while(*p2++=*p1++);
// printf("%s",p2);
// return 0;
// }

//  Variable	Value
// p1	0x400684 "Name"
// p2	0x0
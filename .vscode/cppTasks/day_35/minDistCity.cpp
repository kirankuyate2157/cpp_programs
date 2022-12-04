#include <bits/stdc++.h>
using namespace std;

int minDistance(int dist[], bool visSet[], int V)
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (visSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[], int V)
{
    printf("Vertex \t\t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t\t\t %d\n", i, dist[i]);
}

int dijkstra(vector<vector<int>> roads, int src)
{
    int V = roads.size();
    int dist[V];
    bool visSet[V];
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, visSet[i] = false;

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {

        int u = minDistance(dist, visSet, V);
        visSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!visSet[v] && roads[u][v] && dist[u] != INT_MAX && dist[u] + roads[u][v] < dist[v])
                dist[v] = dist[u] + roads[u][v];
    }

    // return printSolution(dist, V);
    int low = INT_MAX;
    for (int i = 0; i < V; i++)
    {
        if (i == src)
            continue;
        int g = dist[i];
        // cout << g << " ";
        if (g < low)
            low = g;
    }
    return low;
}

int main()
{
    // [ [ 1, 2, 9 ], [ 2, 3, 6 ], [ 2, 4, 5 ], [ 1, 4, 7 ] ]
    /* Let us create the example roads discussed above */

    vector<vector<int>> node = {{1, 2, 9},
                                {2, 3, 6},
                                {2, 4, 5},
                                {1, 4, 7}};

    int n = node.size();
    vector<vector<int>> roads(n + 1, vector<int>(n + 1, 0));
    //  = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
    //          {4, 0, 8, 0, 0, 0, 0, 11, 0},
    //          {0, 8, 0, 7, 0, 4, 0, 0, 2},
    //          {0, 0, 7, 0, 9, 14, 0, 0, 0},
    //          {0, 0, 0, 9, 0, 10, 0, 0, 0},
    //          {0, 0, 4, 14, 10, 0, 2, 0, 0},
    //          {0, 0, 0, 0, 0, 2, 0, 1, 6},
    //          {8, 11, 0, 0, 0, 0, 1, 0, 7},
    //          {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    vector<pair<int, int>> adj[n];

    for (int i = 0; i < n; i++)
    {
        int u = node[i][0], v = node[i][1], w = node[i][2];
        roads[u][v] = w;
    }
    int min = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        int g = dijkstra(roads, i);
        if (g < min)
            min = g;
    }
    cout << min << endl;
    return 0;
}
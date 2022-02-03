#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> dist, int n)
{
    for (int i = 1; i < n; i++)
    {
        bool flag = false;
        for (int a : dist[i])
        {
            if (flag)
                cout << a << " ";
            else
                cout << "[ ";
            flag = true;
        }
        cout << " ]\n";
    }
}
void floyd(int n, vector<vector<int>> dist)
{

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                {
                    // cout << i << " M " << k << " , " << k << " M " << j << "     ";
                    continue;
                }
                else if (dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    // cout << i << " W " << k << " , " << k << " W " << j << "     ";
                }
            }
    for (int i = 0; i < n; i++)
        if (dist[i][i] < 0)
        {
            cout << "negative edge cycle present\n";
            return;
        }

    // for (int i = 0; i < n; i++)
    int src;
    cin >> src;
    for (int j = 0; j < n; j++)
        if (dist[src][j] != INT_MAX)
            cout << j << " : " << dist[src][j] << "\n";
    cout << "\n";
    print(dist, n);
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<vector<int>> arr(n, vector(n, INT_MAX));
    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < n; j++)
    //         arr[i].push_back(INT_MAX);
    for (int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        arr[u][v] = w;
        arr[v][u] = w;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int a : arr[i])
    //         cout << a << " ";
    //     cout << "\n";
    // }
    floyd(n, arr);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class DSU
{
private:
    int *leader;
    int *Rank;
public:
    DSU(int n)
    {
        leader = new int[n];
        Rank = new int[n];
        for (int i = 0; i < n; i++)
        {
            leader[i] = -1;
            Rank[i] = 1;
        }
    }
    int find(int x)
    {
        if (leader[x] == -1)
            return x;
        return leader[x] = find(leader[x]);
    }
    void Union(int a, int b)
    {
        int u = find(a);
        int v = find(b);
        if (Rank[u] < Rank[v])
        {
            leader[u] = v;
            Rank[v] += Rank[u];
        }
        else
        {
            leader[v] = u;
            Rank[u] += Rank[v];
        }
    }
};

void kruskal(vector<pair<int, pair<int, int>>> edges, int n)
{
    DSU kk(n);
    vector<pair<int, pair<int, int>>> mst;
    sort(edges.begin(), edges.end());
    for (int i = 0; i < edges.size(); i++)
    {
        int weight = edges[i].first;
        int u = edges[i].second.first;
        int v = edges[i].second.second;
        if (kk.find(u) == kk.find(v))
            continue;
        mst.push_back(edges[i]);
        kk.Union(u,v);
    }
    for (auto x : mst)
    {
        cout << x.second.first << " -> " << x.second.second << "  == " << x.first << "\n";
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < e; i++)
    {
        int w, u, v;
        cin >> u >> v >> w;
        edges.push_back({w, {u, v}});
    }
    kruskal(edges, e);

    return 0;
}
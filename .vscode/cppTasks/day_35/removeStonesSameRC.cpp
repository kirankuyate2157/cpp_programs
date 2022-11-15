
#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {

        rank.resize(n + 1, 0);

        parent.resize(n + 1);

        size.resize(n + 1);

        for (int i = 0; i < n; i++)
        {

            parent[i] = i;

            size[i] = 1;
        }
    }

    int findUParent(int node)
    {

        if (node == parent[node])
            return node;

        return parent[node] = findUParent(parent[node]);
    }

    void unionR(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;
        else if (rank[ulp_v] < rank[ulp_u])
            parent[ulp_v] = ulp_u;
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionS(int u, int v)
    {
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if (ulp_u == ulp_v)
            return;

        if (size[ulp_u] > size[ulp_v])
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution
{

public:
    int maxRemove(vector<vector<int>> &stones, int n)
    {

        // Code here

        int maxRow = 0;

        int maxCol = 0;

        for (auto it : stones)
        {

            maxRow = max(maxRow, it[0]);

            maxCol = max(maxCol, it[1]);
        }

        // now make the disjoint set:

        DisjointSet ds(maxRow + maxCol + 2); // why running on +2 no idea

        unordered_map<int, int> stoneNodes; // we need an unordered map to uniqely store

        // now we need to join the components:

        for (auto it : stones)
        {

            int nodeRow = it[0];

            int nodeCol = it[1] + maxRow + 1;

            ds.unionR(nodeRow, nodeCol);

            stoneNodes[nodeRow] = 1;

            stoneNodes[nodeCol] = 1;
        }

        int cnt = 0;

        for (auto it : stoneNodes)
        {

            if (ds.findUParent(it.first) == it.first)
            {

                cnt++;
            }
        }

        return n - cnt;
    }
};
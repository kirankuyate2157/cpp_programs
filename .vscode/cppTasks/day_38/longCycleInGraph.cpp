#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /*
        simple dfs
        extra visit array which will take care of inner recursion in dfs in that way we can find double visisted node that time cnt will we can get

    */
    int res = -1;
    void dfs(int u, vector<int> &edges, vector<int> &cnt, vector<bool> &vis, vector<bool> &inRec)
    {
        if (u != -1)
        {
            vis[u] = true;
            inRec[u] = true;
            int v = edges[u];
            if (v != -1 && !vis[v])
            {
                cnt[v] = cnt[u] + 1;
                dfs(v, edges, cnt, vis, inRec);
            }
            else if (v != -1 && inRec[v] == true)
            {
                int k = cnt[u] - cnt[v] + 1;
                res = max(res, k);
            }
            inRec[u] = false;
        }
    }
    int longestCycle(vector<int> &edges)
    {
        int n = edges.size();
        vector<int> cnt(n, 1);
        vector<bool> vis(n, false);
        vector<bool> inRec(n, false);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, edges, cnt, vis, inRec);
            }
        }
        return res;
    }
};
int main()
{
    vector<int> edges = {3, 3, 4, 2, 3};
    Solution obj;

    cout << "The longest cycle in the graph  : " << obj.longestCycle(edges);
    return 0;
}
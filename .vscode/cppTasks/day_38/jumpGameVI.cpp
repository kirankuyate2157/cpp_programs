#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        int n = arr.size();
        unordered_map<int, vector<int>> mp;
        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        vis[0] = true;
        int st = 0;
        while (!q.empty())
        {
            int sz = q.size();

            while (sz--)
            {
                int cur = q.front();
                // cout << cur << ",";
                q.pop();
                if (cur == n - 1)
                    return st;
                int l = cur - 1;
                int r = cur + 1;
                if (l >= 0 && !vis[l])
                {
                    q.push(l);
                    vis[l] = true;
                }
                if (r <= n - 1 && !vis[r])
                {
                    q.push(r);
                    vis[r] = true;
                }
                for (auto x : mp[arr[cur]])
                {
                    if (!vis[x])
                    {
                        q.push(x);
                        vis[x] = true;
                    }
                }
                mp.erase(arr[cur]);
            }
            st++;
        }
        return -1;
    }
};

int main()
{
    vector<int> arr = {100, -23, -23, 404, 100, 23, 23, 23, 3, 404};

    Solution obj;
    cout << "number of steps required to reach end : " << obj.minJumps(arr);

    return 0;
}
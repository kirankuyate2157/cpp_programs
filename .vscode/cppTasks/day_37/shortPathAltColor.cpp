#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges)
    {
        vector<vector<int>> gf(n + 1, vector<int>(n + 1, 0));
        int x = redEdges.size(), y = blueEdges.size();
        for (int i = 0; i < x; i++)
        {
            gf[redEdges[i][0]][redEdges[i][1]] = 1;
        }
        for (int i = 0; i < y; i++)
        {
            if (gf[blueEdges[i][0]][blueEdges[i][1]] == 1)
                gf[blueEdges[i][0]][blueEdges[i][1]] = 2;
            else
                gf[blueEdges[i][0]][blueEdges[i][1]] = -1;
        }

        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = 0; j < n; j++)
        //     {
        //         cout << gf[i][j] << " ";
        //     }
        //     cout << " \n";
        // }
        set<pair<int, int>> st;
        vector<int> ans(n, INT_MAX);
        queue<pair<int, int>> q;

        ans[0] = 0;

        q.push({0, -1});
        q.push({0, 1});
        int cnt = 0;

        while (!q.empty())
        {
            int sz = q.size();
            cnt++;
            for (int i = 0; i < sz; i++)
            {
                auto x = q.front();
                // cout << x.first << " " << x.second << " , ";
                q.pop();
                for (int k = 1; k < n; k++)
                {
                    if (gf[x.first][k] == -x.second || gf[x.first][k] == 2)
                    {

                        if (st.find({k, -x.second}) != st.end())
                            continue;
                        q.push({k, -x.second});
                        ans[k] = min(ans[k], cnt);
                        st.insert({k, -x.second});
                    }
                }
            }

            // cout << "\n";
        }
        for (int i = 1; i < n; i++)
        {
            if (ans[i] == INT_MAX)
                ans[i] = -1;
        }
        return ans;
    }
};
int main()
{
    vector<vector<int>> red1 = {{0, 1}, {1, 2}},
                        blue1 = {};
    vector<vector<int>> red = {{2, 3}, {0, 5}, {3, 1}, {5, 0}, {3, 0}, {0, 0}},
                        blue = {{1, 2}, {3, 2}, {1, 0}, {2, 2}, {5, 2}};
    int n = 6;
    int n1 = 3;
    Solution obj;
    vector<int> ans = obj.shortestAlternatingPaths(n1, red1, blue1);
    cout << " edge colors alternate along the path  :\n";
    for (auto x : ans)
        cout << x << " ";

    return 0;
}
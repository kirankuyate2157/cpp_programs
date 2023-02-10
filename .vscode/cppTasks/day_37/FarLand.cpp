#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int res = 0;
    int maxDistance(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        unordered_set<string> st;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    string x = to_string(i) + "$" + to_string(j);
                    st.insert(x);
                }
            }
        }
        if (q.empty())
            return -1;
        return bfs(n, m, q, st, grid);
    }

    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int bfs(int n, int m, queue<pair<int, int>> &q, unordered_set<string> st, vector<vector<int>> &grid)
    {
        int cnt = 0;
        //  for(auto x:st)cout<<x<<",";
        while (!q.empty())
        {

            int sz = q.size();
            for (int s = 0; s < sz; s++)
            {
                pair<int, int> p = q.front();
                // cout << p.first << "-" << p.second << ", ";
                q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int x = p.first + dir[k][0];
                    int y = p.second + dir[k][1];
                    if (x >= n || x < 0 || y >= m || y < 0 || grid[x][y] == 1)
                        continue;
                    if (st.find(to_string(x) + "$" + to_string(y)) != st.end())
                    {
                        // cout<<x<<"*"<<y<<" ";
                        continue;
                    }
                    q.push({x, y});
                    st.insert(to_string(x) + "$" + to_string(y));
                }
            }
            cnt++;
            //  cout<<" -> ";
            //  for(auto x:st)cout<<x<<", ";
            //  cout<<"\n";
        }
        return cnt == 1 ? -1 : cnt - 1;
    }
};
int main()
{
    vector<vector<int>> grid = {{1, 0, 1},
                                {0, 0, 0},
                                {1, 0, 1}};
    Solution obj;
    cout << "nearest land cell is maximized dist : " << obj.maxDistance(grid) << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        using pp = pair<int, pair<int, int>>;

        for (int i = 0; i < tasks.size(); i++)
        {
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        vector<int> ans;
        int Mt = 0, i = 0;
        while (ans.size() < tasks.size())
        {
            if (i < tasks.size() && q.empty())
            {
                Mt = max(Mt, tasks[i][0]);
            }
            while (i < tasks.size() && Mt >= tasks[i][0])
            {
                q.push({tasks[i][1], tasks[i][2]});
                i++;
            }
            auto x = q.top();
            q.pop();
            Mt = min(1000000000, x.first + Mt);
            ans.push_back(x.second);
        }
        return ans;
    }
};

int main()
{
    vector<vector<int>> p = {{1, 2}, {2, 4}, {3, 2}, {4, 1}};
    Solution Obj;
    vector<int> ans = Obj.getOrder(p);
    cout << "Order of he Process is : ";
    for (auto x : ans)
        cout << x << ",";

    return 0;
}
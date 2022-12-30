#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> ans;
        vector<int> arr;
        int n = graph.size();

        arr.push_back(0);
        giveme(0, arr, n, ans, graph);

        return ans;
    }

    void giveme(int i, vector<int> &arr, int n, vector<vector<int>> &ans, vector<vector<int>> &graph)
    {
        if (i == n - 1)
        {
            ans.push_back(arr);
            return;
        }

        for (auto x : graph[i])
        {
            arr.push_back(x);
            giveme(x, arr, n, ans, graph);
            arr.pop_back();
        }
    }
};

int main()
{
    vector<vector<int>> graph = {{4, 3, 1}, {3, 2, 4}, {3}, {4}, {}};
    Solution obj;
    vector<vector<int>> ans = obj.allPathsSourceTarget(graph);
    cout << "All possible paths from  source : \n";
    cout << "[ ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[";
        for (auto x : ans[i])
        {
            cout << x << ",";
        }
        cout << "], ";
    }
    cout << "]\n";
    return 0;
}
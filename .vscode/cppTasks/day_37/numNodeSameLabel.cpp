#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> fun(vector<vector<int>> &list, string &labels, int i, vector<int> &result)
    {
        vector<int> ans(26, 0);
        result[i] = 1;
        ans[labels[i] - 'a'] = 1;

        for (int j = 0; j != list[i].size(); j++)
            if (!result[list[i][j]])
            {
                vector<int> tmp = fun(list, labels, list[i][j], result);
                for (int k = 0; k != 26; k++)
                    ans[k] += tmp[k];
            }

        result[i] = ans[labels[i] - 'a'];

        return ans;
    }

    vector<int> countSubTrees(int n, vector<vector<int>> &edges, string labels)
    {
        vector<vector<int>> list(n);
        vector<int> result(n, 0);
        for (int i = 0; i != edges.size(); i++)
        {
            list[edges[i][0]].push_back(edges[i][1]);
            list[edges[i][1]].push_back(edges[i][0]);
        }

        fun(list, labels, 0, result);
        return result;
    }
};
int main()
{
    int n = 7;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}};
    string label = "abaedcd";
    Solution obj;
    vector<int> ans = obj.countSubTrees(n, edges, label);
    cout << " Number of nodes in the subtree of the ith node which have the same label as node : \n";
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
    return 0;
}
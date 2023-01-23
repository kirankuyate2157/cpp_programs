#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        if (n == 1)
            return 1;
        map<int, int> mp;
        for (auto x : trust)
        {
            mp[x[1]]++;
        }
        int ans = -1, y = -1;
        for (auto x : mp)
        {
            // cout << x.first << " : " << x.second << "\n";
            if (x.second > ans)
            {
                ans = x.second;
                y = x.first;
            }
        }
        for (auto x : trust)
        {
            if (x[0] == y)
                return -1;
        }
        return (ans == n - 1 || ans == n) ? y : -1;
    }
};
int main()
{
    int n = 3;
    vector<vector<int>> trust = {{1, 3}, {2, 3}};
    Solution obj;
    cout << "label of the town judge : " << obj.findJudge(n, trust) << endl;
    return 0;
}
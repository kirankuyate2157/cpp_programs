#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string frequencySort(string s)
    {
        map<char, int> mp;
        for (char x : s)
        {
            mp[x]++;
        }
        string ans = "";
        vector<pair<int, char>> v;
        for (auto x : mp)
        {
            v.push_back({x.second, x.first});
        }
        sort(v.begin(), v.end());

        for (auto x : v)
        {
            // cout<<x.first<<" ";
            int k = x.first;
            while (k--)
            {
                ans += x.second;
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    string s = "sjjndadaaaaa";
    Solution obj;
    cout << obj.frequencySort(s);

    return 0;
}
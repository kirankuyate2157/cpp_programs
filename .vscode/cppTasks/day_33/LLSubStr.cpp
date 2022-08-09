#include <bits/stdc++.h>
using namespace std;
// O(n)
int LLsubString(string s)
{
    if (s.length() == 0)
        return 0;
    int l = 0, r = 0, ans = 0;
    unordered_map<char, int> mp;
    while (r < s.length())
    {
        if (mp[s[r]] != -1)
            l = max(l, mp[s[r]] + 1);
        mp[s[r]] = r;
        ans = max(ans, r - l + 1);
        r++;
    }
    return ans;
}
// O(2*n)
int LLsubString1(string s)
{
    if (s.length() == 0)
        return 0;
    int l = 0, r = 0, ans = 0;
    set<char> st;
    while (l <= r && r < s.length())
    {
        // int x = 0;
        while (st.find(s[r]) != st.end())
        {
            // x++;
            // cout << s[r] << " ";
            st.erase(s[l]);
            l++;
        }
        // cout << x << ".. ";

        ans = max(ans, r - l + 1);
        st.insert(s[r++]);
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << LLsubString(s) << "\n";
    }

    return 0;
}
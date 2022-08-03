#include <bits/stdc++.h>
using namespace std;

void perm(string s, string sub, vector<string> &ans)
{
    if (s.length() == 0)
    {
        int u = 0, l = 0;
        for (char x : sub)
        {
            if (x >= 'A' && x <= 'Z')
                u++;
            else
                l++;
        }
        if (u >= l)
            ans.push_back(sub);
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        string ros = s.substr(0, i) + s.substr(i + 1);
        // cout << ros << "+" << c << " ";
        perm(ros, sub + c, ans);
    }
}

void solve(string s, vector<string> &ans)
{
    if (s.length() < 1)
        return;
    string x;
    for (int i = 0; i < s.length(); i++)
    {
        x = s.substr(i);
        int u = 0, l = 0;
        for (char c : x)
        {
            if (c >= 'A' && c <= 'Z')
                u++;
            else
                l++;
        }
        if (u > 1)
            ans.push_back(x);
    }
}

int main()
{
    string s = "AcbEF";
    vector<string> ans;
    solve(s, ans);
    // perm(s, "", ans);
    cout << ans.size() << endl;
    return 0;
}
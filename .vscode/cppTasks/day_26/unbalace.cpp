#include <bits/stdc++.h>
using namespace std;

void solve(string s)
{
    if (s.length() < 1)
        return;
    vector<int> pos;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ')')
        {
            pos.push_back(pos.back() + 1);
        }
    }
    int open = 0, close = 0, mini = pos[1];
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            open++;
            if (open >= pos.size()){
                break;
                }

            int ans = pos[open] - pos[close] - i * (open - close) - ((open - close) * (open - close - 1)) / 2;
            mini = min(mini, ans);
        }
        else
        {
            close++;
        }
    }
    cout << "minimum swaping  ->   " << mini << "\n";
}

int main()
{
    string s = "((()))(())";
    solve(s);
    cout<<"llp\n\n";

    return 0;
}
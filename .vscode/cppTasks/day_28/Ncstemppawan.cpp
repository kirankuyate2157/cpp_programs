#include <bits/stdc++.h>
using namespace std;

void cnt(int a, set<int> &s, queue<int> &q)
{
    cout << 1 << " ";
    a += 3;
    q.push(a);
    s.insert(a);
    a -= 6;
    q.push(a);
    s.insert(a);
    a *= 2;
    q.push(a);
    s.insert(a);
}

int solve(int a, int b)
{
    unordered_set<int> s;
    queue<int> q;
    s.insert(a);
    while (b--)
    {
        int z = q.size();
        while (!q.empty() && z)
        {
            cnt(q.front(), s, q);
            q.pop();
            z--;
        }
        cnt(a, s, q);
        b--;
    }
    return s.size();
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, ans = 1, i = 1, add = 4;
        cin >> a >> b;
        cout << solve(a, b) << "\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    if (n % 2 == 0)
    {
        int mid = n / 2;
        int i = 0;
        while (mid < n)
        {
            if (s[i++] != s[mid++]){
                cout << "NO\n";
                return;}

        }
        cout << "YES\n";
        return;
    }
    else
    {
        cout << "NO\n";
        return;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long n, x, c = 5;
    cin >> n >> x;
    long y = n, z = x;
    int i = 0;
    // while (c--)
    // {
        n = y, x = z;
        // cout << "n -" << n << " "
        //      << "x -" << x << "   ";
        unordered_map<long, long> map(n);
        while (n > 1)
        {
            // cout << i << "^" << x;
            int a = i ^ x;
            // cout << "=" << a << "  ";
            if (a == 0 || a > 500000 || map[a] == 1)
            {
                if (a > 500000)
                    cout << "...";
                i++;
                continue;
            }
            cout << i << " ";
            x = a;
            map[i] = 1;
            n--;
            i++;
        }
        cout << x << "\n";
    // }
    // cout << "\n";
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
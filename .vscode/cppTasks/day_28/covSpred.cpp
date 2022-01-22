#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long int n;
    cin >> n;
    long x;
    cin >> x;
    if (n == 0)
    {
        cout << "0\n";
        return;
    }
    long long int inf = 1;
    int m = 1;
    for (int i = 0; i < x; i++)
    {
        if (inf >= n)
        {
            inf = n;
            break;
        }
        if (i % 10 == 0)
        {
            m++;
        }
        inf *= m;
    }
    cout << inf << "\n";
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
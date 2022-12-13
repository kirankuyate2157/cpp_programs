#include <bits/stdc++.h>
using namespace std;

// macros
#define nline "\n"
#define pb push_back
#define mod 1e9 + 7
#define ll long long

void solve()
{
    ll n, k;
    cin >> n >> k;
    ll x = (n * (n + 1)) / 2;
    if (x > k)
    {
        cout << -1 << "\n";
        return;
    }
    int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sum += (n - i);
    }
    x = k - sum;
    for (int i = 0; i < n - 1; i++)
        cout << 1 << " ";
    cout << x << "\n";
}
int main()
{
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    // fast io
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tt;
    cin >> tt;
    while (tt--)
    {

        solve();
    }
}

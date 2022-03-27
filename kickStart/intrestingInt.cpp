#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int dp[10001][10001];
int ds[10001][10001];
int main()
{
    int t, T = 0;
    cin >> t;

    while (T++ < t)
    {
        ll A, B, cnt = 0;
        cin >> A >> B;
        for (ll i = A; i <= B; i++)
        {
            ll x = i, p = 1, s = 0;
            while (x > 0)
            {
                s += x % 10;
                p *= x % 10;
                x /= 10;
            }
            if (s % p == 0)
            {
                cnt++;
            }
        }
        cout << "Case #" << T << ": " << cnt << "\n";
    }

    return 0;
}
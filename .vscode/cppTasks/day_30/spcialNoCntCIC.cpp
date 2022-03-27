#include <bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> dp(10, -1);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        ll n;
        cin >> n;
        ll cnt = 0;
        for (ll i = 1; i <= n; i++)
        {
            ll x = i;
            // if (dp[x] > 0)
            // {
            //     cnt++;
            //     continue;
            // }
            ll qpro = 1;
            ll qSum = 0;
            while (x > 0)
            {
                ll y = x % 10;
                qpro *= y;
                    qSum += dp[y] = pow(y, 4);
                x /= 10;
            }

            if (__gcd(qSum, qpro) > 1)
            {
                dp[i] = 1;
                cnt++;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}
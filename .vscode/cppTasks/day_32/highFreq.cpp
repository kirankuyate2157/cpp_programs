#include <bits/stdc++.h>
using namespace std;
#define ll long long
void pint(ll n)
{
    if (n % 2 == 0)
        cout << (n / 2) << "\n";
    else
        cout << (n / 2 + 1) << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll arr[n];
        unordered_map<int, int> mp;
        for (ll i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]]++;
        }
        ll cnt1 = INT_MIN;
        ll cnt2 = INT_MIN;
        ll num;
        for (pair<int, int> x : mp)
        {
            if (x.second > cnt1)
            {
                cnt1 = x.second;
                num = x.first;
            }
        }
        if (cnt1 == n)
        {
            pint(n);
        }
        else
        {
            for (pair<int, int> x : mp)
            {
                if (x.second > cnt2)
                {
                    if (num != x.first)
                        cnt2 = x.second;
                }
            }
            if (cnt2 > cnt1 / 2)
                cout << cnt2 << "\n";
            else
                pint(cnt1);
        }
    }
    return 0;
}
#include <bits/stdc++.h>
#define mood 998244353
#define ll long long int
using namespace std;

ll n, a[10001], Result, sum;
vector<ll> A, B;

struct Tree
{
    vector<vector<pair<ll, ll>>> a;
    vector<ll> Nm, Sm, Mx, Su, Cs;
    ll n, Ans1 = 2147483647, Ans2 = 0;
    void init()
    {
        cin >> n;
        a.resize(n + 1);
        Cs.resize(n + 1);
        Nm.resize(n + 1);
        Sm.resize(n + 1);
        Mx.resize(n + 1);
        Su.resize(n + 1);
        for (ll i = 0; i <= n; ++i)
        {
            Nm[i] = Sm[i] = Mx[i] = Cs[i] = Su[i] = 0;
            a[i].clear();
        }
        ll x, y, z;
        for (ll i = 1; i < n; ++i)
        {
            cin >> x >> y >> z;
            a[x].push_back({y, z});
            a[y].push_back({x, z});
        }
    }

    void solve()
    {
        init();
        DFS1(1, 0);
        ll um = n, x = 0;
        for (ll i = 1; i <= n; ++i)
            if (Mx[i] < um)
            {
                um = Mx[i];
                x = i;
            }
        DFS1(x, 0);
        Ans1 = Cs[x] % mood;
        DFS2(1, 0);
        for (ll i = 1; i <= n; ++i)
            Ans2 = (Ans2 + Sm[i]) % mood;
    }
    void DFS1(ll p, ll fa)
    {
        Su[p] = 1;
        Cs[p] = 0;
        Mx[p] = 0;
        for (auto to : a[p])
        {
            if (to.first == fa)
                continue;
            DFS1(to.first, p);
            Su[p] += Su[to.first];
            Mx[p] = max(Mx[p], Su[to.first]);
            Cs[p] += Cs[to.first] + Su[to.first] * to.second;
        }
        Mx[p] = max(Mx[p], n - Su[p]);
    }

    void DFS2(ll p, ll fa)
    {
        for (auto to : a[p])
        {
            if (to.first == fa)
                continue;
            DFS2(to.first, p);
            ll T = (Sm[to.first] + Nm[to.first] * to.second) % mood;
            Ans2 += (T * Nm[p] % mood + Sm[p] * Nm[to.first] % mood) % mood;
            Nm[p] += Nm[to.first];
            Sm[p] = (Sm[p] + T) % mood;
        }
        Nm[p]++;
    }
};
Tree T[10001];

int main()
{
    cin >> n;
    for (ll i = 1; i <= n; ++i)
    {
        T[i].solve();
        sum += T[i].n;
        B.push_back(T[i].n);
    }
    for (ll i = 1, x; i < n; ++i)
    {
        cin >> x;
        A.push_back(x);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    reverse(A.begin(), A.end());
    for (ll i = 1; i <= n; ++i)
        Result = (Result + T[i].Ans2 + T[i].Ans1 * (sum - T[i].n) % mood) % mood;
    for (ll i = 0; i < n - 1; ++i)
        Result = (Result + B[i] * (sum - B[i]) % mood * A[i]) % mood;
    cout << Result << endl;
    return 0;
}
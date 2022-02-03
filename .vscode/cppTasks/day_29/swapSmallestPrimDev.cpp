#include <bits/stdc++.h>
using namespace std;

vector<int> init()
{
    int q = 100006;
    vector<int> sieve(q);

    for (int i = 0; i < q; ++i)
        sieve[i] = i;

    for (int i = 2; i * i <= q; ++i)
    {
        if (sieve[i] == i)
        {
            for (int j = i * i; j <= q; j += i)
            {
                if (sieve[j] == j)
                    sieve[j] = i;
            }
        }
    }
    return sieve;
}

int minSwaps(int N, vector<int> A)
{
    vector<int> sieve = init();
    unordered_map<int, int> freq_prime;
    for (int i = 0; i < N; ++i)
        freq_prime[sieve[A[i]]]++;

    vector<int> vis(N, 0);

    vector<pair<int, int>> sorted(N);

    for (int i = 0; i < N; ++i)
    {
        sorted[i] = {A[i], i};
    }

    int ans = 0;
    sort(sorted.begin(), sorted.end());
    for (int i = 0; i < N; ++i)
    {
        if (vis[i] == 1 or vis[i] == -1 or (sorted[i].second == i))
            continue;

        if (freq_prime[sieve[sorted[i].first]] <= 1)
            return -1;

        int j = i;
        int d_p = sieve[sorted[i].first];
        int cycle = -1;

        while (vis[j] != 1)
        {

            if (d_p == sieve[sorted[j].first])
            {
                vis[j] = 1;
                cycle++;
            }
            else
            {
                vis[j] = -1;
            }
            j = sorted[j].second;
        }

        if (cycle > 0)
            ans += cycle;
    }

    for (int i = 0; i < N; ++i)
    {
        if (vis[i] == -1)
            return -1;
    }

    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }
        cout<<minSwaps(n,arr)<<"\n";
    }
    return 0;
}
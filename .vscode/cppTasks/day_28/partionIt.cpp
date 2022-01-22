#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = 1e5 + 5;
bool prime[MAX];
int spf[MAX];
void sieve()
{
    fill(prime, prime + MAX, true);
    for (int i = 0; i < MAX; i++)
        spf[i] = i;
    prime[0] = prime[1] = false;
    for (int i = 2; i < MAX; i++)
    {
        if (prime[i])
        {
            for (int j = i * i;j < MAX; j += i)
            {
                if (prime[j])
                    spf[j] = i;
                prime[j] = false;
            }
        }
    }
}

// vector<int> prm(30, 0);
// void prime(int x)
// {

//     // prm[1]=1;prm[2]=1;
//     bool flg = true;
//     for (int i = 1; i < x; i++)
//     {
//         flg = true;
//         for (int j = 2; j < i; j++)
//         {
//             if (i % j == 0)
//             {
//                 flg = false;
//                 break;
//             }
//         }
//         if (flg)
//             prm[i] = 1;
//     }
//     //    for (int i = 0; i < n + 1; i++)
//     //     {
//     //         cout << i << " ";
//     //     }
//     //     cout << "\n";
//     //     for (int l=0 ;l<=n;l++)
//     //     {
//     //         cout << prm[l] << " ";
//     //     }
// }

void solve()
{
    ll n, k;
    cin >> n >> k;
    // prime(n);

    vector<int> v1;
    vector<int> v2 = {1};
    int c1 = 0, c2 = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!prime[i])
        {
            v1.push_back(i);
            c1++;
        }
        else
        {
            if (i * 2 <= n)
            {
                v1.push_back(i);
                c1++;
            }
            else
            {
                v2.push_back(i);
                c2++;
            }
        }
    }
    // cout << "\nv1 = ";
    // for (auto a : v1)
    // {
    //     cout << a << " ";
    // }
    // cout << "\nv2 = ";
    // for (int i=0;i<c2;i++)
    // {
    //     cout << v2[i] << " ";
    // }
    if (k <= c2 or k >= c1)
    {
        cout << "yes\n";
        if (k <= c2)
        {
            for (int i = 0; i < k; i++)
                cout << v2[i] << " ";
        }
        else
        {
            for (int i = 0; i < c1; i++)
                cout << v2[i] << " ";
            for (int i = 0; i < k - c1; i++)
                cout << v2[i] << " ";
        }
    }
    else
    {
        cout << "No\n";
    }
}

int main()
{
    int t;
    cin >> t;
    sieve();
    while (t--)
    {
        solve();
    }
    // cout << "complete";
    return 0;
}
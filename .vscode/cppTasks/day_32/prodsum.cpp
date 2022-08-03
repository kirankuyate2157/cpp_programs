#include <bits/stdc++.h>
using namespace std;
#define M 998244353
#define ll long long

ll Factor[1000010], Enversion[1000010], FactInv[1000010];
ll CntP(ll x, ll y)
{
    if (x < 0 || y > x)
        return 0;
    return Factor[x] * FactInv[y] % M * FactInv[x - y] % M;
}
void findProdSumPermutation()
{
    ll n, ele, count0 = 0, count1 = 0, Time = 0;

    cin >> n;

    for (ll i = 1; i <= n; ++i)
    {
        cin >> ele;
        count0 += ele == 0;
        count1 += ele == 1;
    }

    for (ll i = 0; i <= count1; ++i)
        Time = (Time + i * CntP(count1 + count0 - i, count0)) % M;
    cout << (((Time * (count0 + 1) - CntP(count1 + count0 - 2, count0 - 1)) % M + M) % M + CntP(count1 + count0 - 2, count0 - 1)) * Factor[count1] % M * Factor[count0] % M << endl;
}

int main()
{
    Factor[0] = Enversion[0] = Enversion[1] = FactInv[0] = FactInv[1] = 1;

    for (ll i = 1; i <= 1000000; ++i)
        Factor[i] = Factor[i - 1] * i % M;
    for (ll i = 2; i <= 1000000; ++i)
        Enversion[i] = M - M / i * Enversion[M % i] % M;
    for (ll i = 2; i <= 1000000; ++i)
        FactInv[i] = FactInv[i - 1] * Enversion[i] % M;
    int T;
    cin >> T;
    while (T--)
    {
        findProdSumPermutation();
    }
    return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// void add(ll int a[], ll int n, vector<vector<ll int>> &v)
// {
//     vector<ll int> temp;
//     for (int i = 0; i < n; i++)
//     {
//         temp.push_back(a[i]);
//     }
//     v.push_back(temp);
// }

// void findPermutations(ll int a[], ll int n, vector<vector<ll int>> &v)
// {

//     sort(a, a + n);
//     cout << "Possible permutations are:\n";
//     do
//     {
//         add(a, n, v);
//     } while (next_permutation(a, a + n));
// }

// ll int sunProd(ll int arr[], ll int n, vector<ll int> temp)
// {
//     ll int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[temp[i] - 1] == 1)
//         {
//             ll x = 0;
//             while (arr[temp[i] - 1] == 1 && i < n)
//             {
//                 i++;
//                 ans++;
//                 x++;
//             }
//             ans += (x * (x - 1) / 2);
//         }
//     }
//     return ans;
// }

// int main()
// {
//     ll int Time;
//     cin >> Time;
//     while (Time--)
//     {
//         ll int n;
//         cin >> n;
//         ll int ans = 0;
//         ll int arr[n];
//         ll int arrI[n];
//         for (int i = 0; i < n; i++)
//         {
//             cin >> arr[i];
//             arrI[i] = i + 1;
//         }
//         vector<vector<ll int>> v;

//         findPermutations(arrI, n, v);

//         for (int i = 0; i < v.size(); i++)
//         {
//             ans %= 998244353;
//             ans += sunProd(arr, n, v[i]);
//         }

//         // geting wrong ans 80%
//         //  int prev = 1, nxt = 1;
//         //  for (int i = 0; i < n; i++)
//         //  {
//         //      // cout << arr[i] << ":";
//         //      ans += arr[i];
//         //      if (i > 0)
//         //      {
//         //          prev = arr[i] * prev;
//         //          // cout << prev << "-:-";
//         //          ans += prev;
//         //      }
//         //      if (i < n - 1 && i > 0)
//         //      {
//         //          nxt = arr[i + 1] * arr[i];
//         //          // cout << nxt << "n";
//         //          ans += nxt;
//         //      }
//         //  }
//         cout << ans << "\n";
//     }
//     return 0;
// }
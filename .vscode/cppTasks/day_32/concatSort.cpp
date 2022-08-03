#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll int t;
    cin >> t;
    while (t--)
    {
        ll int n;
        cin >> n;
        vector<ll int> arr(n), arr2(n);
        for (ll int i = 0; i < n; i++)
        {
            cin >> arr[i];
            arr2[i] = arr[i];
        }
        sort(arr2.begin(), arr2.end());

        pair<ll int, ll int> x = {0, 0};
        bool vis[n] = {false};
        for (ll int i = 0; i < 2; i++)
        {
            x.first = 0;
            while (x.first < n)
            {
                if (!vis[x.first] && arr[x.first] == arr2[x.second])
                {
                    vis[x.first] = true;
                    x.first++;
                    x.second++;
                }
                else
                {
                    x.first++;
                }
            }
        }
        if (x.first == x.second)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

// int main()
//  {
//      ll  int t;
//      cin >> t;
//      while (t--)
//      {
//          ll int n;
//          cin >> n;
//          ll int arr[n];
//          for (ll int i = 0; i < n; i++)
//          {
//              cin >> arr[i];
//          }
//          bool vis[n] = {false};
//          ll int str = -1, end = -1;
//          vector<ll int> v;
//          ll int i = 1, j = 0, ele = arr[0], cnt = 1;
//          v.push_back(arr[0]);
//          while (i < n)
//          {
//              if (arr[i] >= ele)
//              {
//                  ele = arr[i];
//                  vis[i] = true;
//                  cnt++;
//                  v.push_back(arr[i]);
//              }
//              else
//              {
//                  if (j == 0)
//                  {
//                      j = i;
//                      str = arr[j];
//                  }
//              }
//              i++;
//          }

//         cnt++;
//         vis[j] = true;
//         end = arr[j];

//         ele = arr[j++];

//         while (j < n)
//         {
//             if (arr[j] > ele && !vis[j])
//             {

//                 ele = arr[j];
//                 vis[j] = true;
//                 end = ele;
//                 cnt++;
//             }
//             j++;
//         }
//         ll int flg = 0;
//         if (v[0] > end)
//         {
//             flg = 1;
//             // cout << "🔥";
//         }

//         else if (v[v.size() - 1] < str)
//         {
//             flg = 1;
//             // cout << "😎";
//         }
//         else
//         {
//             for (ll int i = 0; i < v.size(); i++)
//             {
//                 if (v[i] < str && v[i + 1] > end)
//                 {
//                     flg = 1;
//                     // cout << "😁";
//                 }
//             }
//         }
//         // cout << "start :" << str << "\tend :" << end << "\n";
//         if (flg)
//             cout << "YES\n";
//         else
//             cout << "NO\n";
//     }
//     return 0;
// }

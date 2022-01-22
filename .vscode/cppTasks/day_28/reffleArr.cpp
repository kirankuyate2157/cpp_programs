#include <bits/stdc++.h> //Not understanded well
using namespace std;
vector<int> nArr;
void decompose(int src, vector<bool> &visited, vector<int> &cycle)
{
    if (visited[src])
        return;
    cycle.push_back(src);
    visited[src] = 1;
    decompose(nArr[src], visited, cycle);
}
void solve()
{
    int n, k;
    cin >> n >> k;
    nArr.resize(n + 1);
    int index = 1;
    for (int i = 1; i <= n; i += 2)
        nArr[i] = index++;
    for (int i = 2; i <= n; i += 2)
        nArr[i] = index++;
    vector<bool> visited(n + 1, 0);
    vector<int> ans(n + 1, 0);
    for (int i = 1; i < n; i++)
    {
        if (visited[i] == 0)
        {
            vector<int> cycle;
            decompose(i, visited, cycle);
            for (int j = 1; j <= cycle.size(); j++)
            {
                ans[cycle[(j + k) % cycle.size()]] = cycle[j];
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    cout << "\n";
}

// int *solve(int arr[], int n, int k)
// {
//     // int n = sizeof(arr) / sizeof(int);
//     int ans[n];
//     while (k--)
//     {
//         int i = 0, p = 0, j = 0;
//         while (j<=n)
//         {
//             if (p >= n)
//             {
//                 p = 1;
//             }
//             ans[j++] = arr[p];
//             p += 2;
//         }
//         cout<<"i -"<<i<<"\n";
//         arr = ans;
//         cout << "j -" << j << "\n";
//         for (auto ele : ans)
//         {
//             cout << ele << " ";
//         }
//         cout << "\n";
//          for (auto ele : arr)
//         {
//             cout << ele << " ";
//         }
//         cout << "\n";
//     }
//     return arr;
// }

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();

        // solve(arr, n, k);
    }

    return 0;
}
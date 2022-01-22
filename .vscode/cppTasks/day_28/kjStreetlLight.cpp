#include <bits/stdc++.h>
using namespace std;
// void solve()
// {

//     long long int n, st; // number of street lights and the position of PS's house on x - axis.
//     cin >> n >> st;
//     long long int a, b; // position of street light  & characteristic
//     long long int v[st + 1] = {0};
//     for (long long int i = 0; i <= st; i++)
//     {
//         v[i] = 0;
//     }
//     while (n--)
//     {
//         cin >> a >> b;
//         if (a - b >= 0)
//         {
//             v[a - b]++;
//         }
//         else
//         {
//             v[0]++;
//         }
//         if (a + b + 1 <= st)
//         {
//             v[a + b + 1]--;
//         }
//     }
//     for (long long int i = 1; i <= st; i++)
//     {
//         v[i] += v[i - 1];
//         // cout<<v[i]<<" ";
//     }
//     for(auto x:v){
//         cout<<x<<" ";
//     }cout<<"---\n";
//     long long int cnt = 0, ans = -999999999999;
//     for (int i = 0; i <= st; i++)
//     {
//         cnt = 0;
//         while (v[i] != 1 && i <= st)
//         {cout<<v[i]<<" ";
//             cnt++;
//             i++;
//         }
//         cout<<" //";
//         ans = max(ans,cnt);
//     }
//     cout << ans << "\n";
// }
void solve()
{
    long long int n, st; // number of street lights and the position of PS's house on x - axis.
    cin >> n >> st;
    long long int a, b; // position of street light  & characteristic
    long long int v[st + 1] = {0};

    while (n--)
    {
        cin >> a >> b;
        long long int i = a - b;
        long long int k = a + b;
        if (k > st)
            k = st;
        if (i < 0)
            i = 0;
        for (i; i <= k; i++)
        {
            v[i]++;
        }
    }
    int f1 = 1;
    long long int ans=INT_MIN;
    long long int cnt = 0;
    for(int i=0;i<=st;i++){
        cnt=0;
        while(v[i]!=1&&i<=st){
            cnt++;
            i++;
        }
        ans=max(ans,cnt);
    }
     for (auto ele : v)
    {
        // cout << ele << ",";
    //     if (ele == 0 && f1)
    //     {
    //         f1 = 0;
    //     }
    //     if (ele != 0 && !f1)
    //     {
    //         break;
    //     }
    //     if (!f1)
    //         cnt++;
    }
    // if (cnt > 100)
    //     cnt = (cnt - 11) % 100;
    cout <<ans << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
// input-->
// 3
// 4 4
// 1 2
// 3 0
// 0 2
// 3 0
// 0 4
// 2 7
// 2 0
// 6 2
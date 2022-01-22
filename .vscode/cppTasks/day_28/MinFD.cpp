#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n, x;
    cin >> n >> x;
    int arr[n];
    // int cnt = 0, dp = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<int>());
    // for(int z:arr)cout<<z<<" ";
    int dp = 0;int i = 0;
    for (; i < n; i++)
    {
        dp += arr[i];
        if (dp >= x)break;
    }
if(dp<x)i=-1;else i+=1;
    cout << i << "\n";
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
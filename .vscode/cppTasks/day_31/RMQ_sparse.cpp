#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[] = {7, 2, 3, 0, 5, 10, 3, 12, 18};
  
    int n = sizeof(arr) / sizeof(int);
    int m = ceil(log2(n));

    vector<vector<int>> dp(2 * n, vector<int>(m, INT_MAX));

    for (int j = 0; j < m; j++){
        for (int i = 0; i < n; i++){
            if (j == 0)
                dp[i][0] = arr[i];
            else
                dp[i][j] = min(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
        }
    }

    for (int i = 0; i < n; i++){
        for (auto x : dp[i])
            cout << x << "  ";
        cout << "\n";
    }

    int q;
    cin >> q;
    while (q--){
        int l, r;
        cin >> l >> r;
        int x = r - l + 1, ans = INT_MAX, cur = l;

        for (int i = m - 1; i >= 0; i--){
            cout << "bit checker " << (x & (1 << i)) << " \n";
            if ((x & (1 << i)) != 0){
                ans = min(ans, dp[cur][i]);
                cur += (1 << i);
            }
        }

        cout << "the minimum no in range " << l << " " << r << " is  " << ans << " \n";
    }

    cout << "\t**********  ye  dil mage more  ************";

    return 0;
}
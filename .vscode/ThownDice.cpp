#include <bits/stdc++.h>
using namespace std;
// recursion DP approch

long long int go(int m, int n, int x, vector<vector<long long int>> &dp)
{
    if (n == 0)
    {
        return x == 0 ? 1 : 0;
    }
    if (dp[n][x] != -1)
    {
        return dp[n][x];
    }
    long long int ways = 0;
    for (int dice = 1; dice <= m && x >= dice; dice++)
    {
        ways += go(m, n - 1, x - dice, dp) * 1ll;
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto x : dp[i])
            cout << x << " ";
        cout << "\n";
    }
    cout<<"\n";
    return dp[n][x] = ways;
}
long long noOfWays(int M, int N, int X)
{
    // code here
    vector<vector<long long int>> dp(N + 1, vector<long long int>(X + 1, -1));
    long long int ans = go(M, N, X, dp);

    return ans;
}

int main()
{
    int M = 6, N = 3, X = 12;

    cout << noOfWays(M, N, X);

    return 0;
}


// GFG approch

// long findWays(int f, int d, int s)
// {
//     // Create a table to store results of subproblems. One extra
//     // row and column are used for simplicity (Number of dice
//     // is directly used as row index and sum is directly used
//     // as column index). The entries in 0th row and 0th column
//     // are never used.
//     long mem[d + 1][s + 1];
//     memset(mem,0,sizeof mem);
//     // Table entries for no dices
//     // If you do not have any data, then the value must be 0, so the result is 1
//     mem[0][0] = 1;
//     // Iterate over dices
//     for (int i = 1; i <= d; i++)
//     {
//         // Iterate over sum
//         for (int j = i; j <= s; j++)
//         {
//             // The result is obtained in two ways, pin the current dice and spending 1 of the value,
//             // so we have mem[i-1][j-1] remaining combinations, to find the remaining combinations we
//             // would have to pin the values ??above 1 then we use mem[i][j-1] to sum all combinations
//             // that pin the remaining j-1's. But there is a way, when "j-f-1> = 0" we would be adding
//             // extra combinations, so we remove the combinations that only pin the extrapolated dice face and
//             // subtract the extrapolated combinations.
//             mem[i][j] = mem[i][j - 1] + mem[i - 1][j - 1];
//             if (j - f - 1 >= 0)
//                 mem[i][j] -= mem[i - 1][j - f - 1];
//         }
//     }
//     for(int i=0;i<=d;i++){
//         for(auto x:mem[i])cout<<x<<" ";
//         cout<<"\n";
//     }
//     return mem[d][s];
// }
 
// // Driver code
// int main(void)
// {
//     cout << findWays(4, 2, 1) << endl;
//     cout << findWays(2, 2, 3) << endl;
//     cout << findWays(6, 3, 12) << endl;
//     // cout << findWays(4, 2, 5) << endl;
//     cout << findWays(4, 3, 5) << endl;
//     return 0;
// }
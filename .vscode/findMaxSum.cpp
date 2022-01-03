#include <bits/stdc++.h>
using namespace std;
int FindMaxSum(int arr[], int n)
{
    int dp[n] = {0};//list oo max sum
     dp[0] = arr[0];//First max sum
     dp[1] = max(dp[0], arr[1]);//second max sum
    for (int i = 2; i < n; i++)//Max_sum in bettween last-max_sum & smu of first and cur numbers
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
    }
    return dp[n - 1];
}
int main()
{
    int arr[] = {4, 6, 35, 7, 90, 5};
    int n = 6;
    cout << FindMaxSum(arr, n);

    return 0;
}

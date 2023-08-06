#include <bits/stdc++.h>
using namespace std;
// 920. Number of Music Playlists

class Solution
{
public:
    long long int m = 1000000000 + 7;
    vector<vector<int>> dp;
    int solve(int cur, int old, int n, int k)
    {
        if (cur == 0 && old == n)
            return 1;
        if (cur == 0 | old > n)
            return 0;
        if (dp[cur][old] != -1)
            return dp[cur][old];

        long long int ans = ((n - old) % m * solve(cur - 1, old + 1, n, k) % m) % m;
        if (old > k)
        {
            ans += ((old - k) % m * solve(cur - 1, old, n, k) % m) % m;
        }

        return dp[cur][old] = ans % m;
    }

    int numMusicPlaylists(int n, int goal, int k)
    {
        dp.resize(goal + 2, vector<int>(goal + 2, -1));
        return solve(goal, 0, n, k);
    }
};

int main()
{
    int n = 3, g = 3, k = 1;
    Solution obj;
    cout << "numMusicPlaylists : " << obj.numMusicPlaylists(n, g, k) << endl;

    return 0;
}

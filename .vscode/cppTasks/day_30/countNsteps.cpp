#include <bits/stdc++.h>
using namespace std;
long long int M = 1000000007ll;
// dp approch ..
long long countWays(int n)
{
    vector<long long> dp(n + 1, 1ll);
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = ((dp[i - 1] % M + dp[i - 2] % M) % M + dp[i - 3] % M) % M;
        cout << dp[i] << " : " << dp[i - 1] << " + " << dp[i - 2] << " + " << dp[i - 3] << " \n";
    }
    return dp[n];
}
//recursion approch..
long long int Kways(int n){
    if(n<=1)return 1;
    if(n==2)return 2;
    return Kways(n-1)+Kways(n-2)+Kways(n-3);
}
// gfg approch 
long long GFGWays(int n)
    {
        long long t[3] = {1, 1, 2};
        if(n<=2)        
            return t[n];
         
        int mod = 1000000007;
        long long ans = 0;
        for(int i=3; i<=n; i++)
        {
            ans = (t[0]+t[1]+t[2])%M;
            cout<<(i%3)<<" : "<<ans<<" \n";
            t[i%3] = ans;
        }
        
        return ans;
    }
int main()
{
    int n;
    cin >> n;
    // cout<<countWays(n);
    // cout<<Kways(n);
    cout<<GFGWays(n);

    return 0;
}
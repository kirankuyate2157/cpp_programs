#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        // for (int i = 0; i < n; i++)
        // {
        //     ans += abs(s[i + 1] - s[i]);
        // }
        // cout<<n-1<<" -- "<<ans;
        // int remaining = (n - 1) - ans;
        for(int i=0;i<n;i++){
            if(s[i+1]==s[i]){
                ans++;
            }
        }
        if (ans % 3)
            cout << "-   JJ\n";
        else
            cout << "-   Uttu\n";
    }

    return 0;
}
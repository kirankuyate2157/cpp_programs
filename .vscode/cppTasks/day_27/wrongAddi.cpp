#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    string a, s;
    cin >> a >> s;
    int i = a.length() - 1;
    int j = s.length() - 1;
    string ans = "";
    if (a == s)
    {
        cout << "0\n";
    }
    else if (stoll(a) > stoll(s))
    {
        cout << "-1\n";
    }
    else
    {
        while (i >= 0)
        {
            if (a[i] > s[j])
            {
                if (s[j-1] == '1')
                {
                    char cha = (char)(10 + ((s[j] - '0') - (a[i] - '0')) + '0');
                    ans = cha + ans;
                    j -= 2;
                    i--;
                }
                else
                {
                    cout << "-1\n";
                    return;
                }
            }
            else
            {
                char cha = (char)(((s[j] - '0') - (a[i] - '0')) + '0');
                ans = cha + ans;
                j--;
                i--;
            }
            if (j< 0 && i>= 0)
            {
                cout << "-1\n";
                return;
            }
        }
        while (j >= 0)
        {
            ans = s[j] + ans;
            j--;
        }
        int k = ans.length();
        i = 0;
        for ( i; i <k; i++)
        {
            if (ans[i] != '0')
            {
                break;
            }
        }

        for (int x=i; x < k; x++)
            cout << ans[x];
        // cout << ans;
        cout << "\n";
    }
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
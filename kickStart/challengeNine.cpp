#include <bits/stdc++.h>
using namespace std;
#define ll long long int
/*
// first approch
int main()
{
    int t, T = 0;
    cin >> t;
    while (T++ < t)
    {
        string n;
        cin >> n;
        string x = "", y = "";
        bool flg = false;
        ll ans = 0, i = 0;
        if (stoll(n, nullptr, 10) % 9 == 0)
        {
            cout << "Case #" << T << ": " << n << "\n";
            continue;
        }
        while (true)
        {
            x = n;
            y = n;
            reverse(x.begin(), x.end());
            x += to_string(i);
            reverse(x.begin(), x.end());
            y += to_string(i);
            if (stoll(x, nullptr, 10) % 9 == 0 || stoll(y, nullptr, 10)% 9 == 0)
            {

                stoll(x, nullptr, 10) <= stoll(y, nullptr, 10)? ans =stoll(x, nullptr, 10) : ans = stoll(y, nullptr, 10);

                break;
            }
            i++;
        }
        cout << "Case #" << T << ": " << ans << "\n";
    }
    return 0;
}
*/
// second approch
int main()
{
    int T = 0, t;
    cin >> t;
    while (T++ < t)
    {
        string n;
        cin >> n;
        ll sum = 0;
        for (auto k:n)
        {
            sum += (k-'0');
        }//taking sum of all characters numberers
        cout<<"Case #"<<T<<": ";
        if (sum % 9 == 0)
        {
            cout << n[0] << "0";
            if (n.length() > 1)
            {
                n = n.substr(1);
                cout << n;
            }
        }
        else
        {
            ll i = 0;
            ll x = 9 - sum % 9; //taking x from sum
            for (i = 0; i < n.length(); i++)
            {
                if ((n[i] - '0') > x)
                    break;
                else
                    cout << n[i];
            }
            cout << x;
            if (i < n.length())
            {
                n = n.substr(i);
                cout << n;
            }
        }
        cout << "\n";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ll int t;
    cin >> t;
    while (t--)
    {
        ll int a, b;
        cin >> a >> b;
        ll int x = 0, y = 0, diff = INT_MIN;

        if (b < 2 * a)
        {
            cout << b << " " << b << endl;
            continue;
        }
        else if (b >= 2 * a && b % a == 0)
        {
            cout << b << " " << a << endl;
            continue;
        }
        else
        {
            ll int k = b / 2;
            if (b >= 2 * a)
                k = 2 * a;
            for (ll int i = a; i < k; i++)
            {
                ll int temp = b / i;
                ll int curDiff = temp * i - i;
                if (curDiff > diff)
                {
                    x = i;
                    y = i * temp;
                    diff = curDiff;
                }
            }
        }

        // for (ll int i = b; i > 0; i--)
        // {
        //     for (ll int j = 1; j <= b; j++)
        //     {
        //         if (__gcd(i, j) >= a)
        //         {
        //             ll int res = abs(i - j);
        //             diff = max(diff, res);
        //             if (diff == res)
        //             {
        //                 x = i, y = j;
        //             }
        //         }
        //     }
        // }
        // cout << diff << endl;
        // cout << "ans : "
        //  << "(" << x << "," << y << ")\n";
        cout << x << " " << y << endl;
    }
    return 0;
}
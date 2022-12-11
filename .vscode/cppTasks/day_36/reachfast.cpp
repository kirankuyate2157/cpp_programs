#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, k;
        cin >> x >> y >> k;
        int cnt = 0;
        if (x == y)
            cout << "0\n";
        else
        {
            if (x > y)
            {
                while (x > y)
                {
                    x -= k;
                    cnt++;
                }
            }
            else
            {
                while (x < y)
                {
                    x += k;
                    cnt++;
                }
            }
            cout << cnt << "\n";
        }
    }
    return 0;
}

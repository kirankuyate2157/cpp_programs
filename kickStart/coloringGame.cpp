#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int T, t = 1;
    cin >> T;
    while (t <= T)
    {
        // * - # - * - # - * -  #  -   *  -  #
        // 0 1 2 3 4 5 6 7 8 9 10  11  12 13 14 15 16 17 18 19 20 21 22 23
        ll n;
        cin >> n;
        ll x = n / 4;
        cout << "Case #" << t << ": " << (x + 1) << endl;
        t++;
    }

    return 0;
}

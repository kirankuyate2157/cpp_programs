#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, n, r;
        cin >> x >> y >> n >> r;
        int xc = r / x;
        int yc = r / y;
        int ans = 0;
        if (yc >= n)
        {
            yc = n;
            cout << "0 " << yc << "\n";
            continue;
        }
        if (r / x < n)
        {
            cout << "-1\n";
            continue;
        }
        int ty, rm;

        ty = y * n;
        rm = (x - y);
        xc = ((r - ty) / rm);
        if (((r - ty) % rm) != 0)
            xc += 1;

        cout << xc << " " << n - xc << endl;
    }
    return 0;
}
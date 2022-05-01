#include <bits/stdc++.h>
using namespace std;
int main()
{
    long double pi = 3.14159265359;
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        double r, a, b;
        cin >> r >> a >> b;
        double area = 0;
        area += r * r * pi;
        while (true)
        {
            // left
            r = r * a;
            if (r < 1)
                break;
            // cout << r << " : ";
            area += r * r * pi;
            r = r / b; // right
            if (r < 1)
                break;

            area += r * r * pi;
            // cout << " -> " << fixed << setprecision(6) << area << endl;
        }
        cout << "Case #" << t << ": ";
        cout << fixed << setprecision(6) << area << "\n";

        t++;
    }
    return 0;
}
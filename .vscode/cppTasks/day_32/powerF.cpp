#include <bits/stdc++.h>
using namespace std;
double powerF(double x, int n)
{
    double ans = 1.0;
    for (int i = 0; i < n; i++)
        ans = ans * x;
    return ans;
}

double mypower(double x, int n)
{
    double ans = 1.0;
    long long m = n;
    if (m < 0)
        m = -1 * m;
    while (m > 0)
    {
        if (m % 2)
        {
            ans = ans * x;
            m = m - 1;
            // cout << "$" << ans << " " << x << " " << m << " ..";
        }
        else
        {
            x = x * x;
            m = m / 2;
            // cout << "^" << x << " " << m << " ..";
        }
    }
    if (n < 0)
        ans = (double)1.0 / (double)ans;
    return ans;
}
int main()
{
    cout << mypower(2.0, 8);

    return 0;
}
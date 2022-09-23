#include <bits/stdc++.h>
using namespace std;

double multiply(double num, double n)
{
    double result = 1.0;
    for (int i = 0; i < n; i++)
    {
        result = num * result;
    }
    return result;
}

void getroot(int n, int m)
{
    double l = 1.0;
    double r = m;
    double esp = 1e-7;
    while ((r - l) > esp)
    {
        double mid = (l + r) / 2.0;
        if (multiply(mid, n) < m)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << "the " << n << "th root of " << m << " is " << r << endl;
}

int main()
{
    int n = 3, m = 27;
    getroot(n, m);
    return 0;
}
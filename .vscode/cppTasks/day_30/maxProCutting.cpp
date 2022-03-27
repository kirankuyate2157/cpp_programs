#include <bits/stdc++.h>
using namespace std;
int maxCuttingPro(int n)
{
    if (n <= 1)
        return 0;
    int maxi = 0;
    for (int i = 1; i < n; i++)
    {
        maxi = max(maxi, max(i * (n - i), maxCuttingPro(n - i) * i));
    }
    return maxi;
}
// gfg_ approch
int maxProd(int n)
{
    int val[n + 1];
    val[0] = val[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        int maxi = 0;
        for (int j = 1; j <= i; j++)
        {
            maxi = max(maxi, max((i - j) * j, j * val[i - j]));
        }
        val[i]=maxi;

    }
    return val[n];
}

int main()
{
    int n;
    cin >> n;
    cout << maxCuttingPro(n);
    cout << "\n";
    cout << maxProd(n);
    return 0;
}
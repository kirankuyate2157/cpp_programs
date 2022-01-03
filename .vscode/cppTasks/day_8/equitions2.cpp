#include <bits/stdc++.h>
using namespace std;

// (1+2/3+4)*(2+3/4+5)*(3+4/5+6)*(........

int main()
{
    int n =8576;
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        res *= ((i + (i + 1)) / ((i + 2) + (i + 3)));
    }
    cout << res;

    return 0;
}
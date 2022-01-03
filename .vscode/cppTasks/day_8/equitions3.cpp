#include <bits/stdc++.h>
using namespace std;
int fact(int a)
{
    int fact = 1;
    for (int i = 1; i < a; i++)
    {
        fact += fact * i;
    }
    return fact;
}

int num(int a)
{
    int res = 0;
    for (int i = 1; i <= a; i++)
    {
        res = res + i;
        // cout<<res<<",";
    }
    return res;
}

int main()
{
    // (1/1!)+(3/2!)+(6/3!)+(10/4!)+(15/5!)+....

    int n = 2;
    float sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += (num(i) / ((fact(i)) + 0.00));
    }
    cout << "the result is ..." << sum;

    return 0;
}
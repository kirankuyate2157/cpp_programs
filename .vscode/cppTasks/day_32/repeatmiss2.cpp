#include <bits/stdc++.h>
using namespace std;
vector<int> repeatedNumber(const vector<int> &arr)
{
    int n = arr.size();
    int set_bit = 0;
    int x = 0, y = 0, xor1 = 0;
    for (int i = 0; i < n; i++)
        xor1 = xor1 ^ arr[i];
    for (int i = 1; i <= n; i++)
        xor1 = xor1 ^ i;
    set_bit = xor1 & ~(xor1 - 1);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & set_bit)
            x = x ^ arr[i];
        else
            y = y ^ arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (i & set_bit)
            x = x ^ i;
        else
            y = y ^ i;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (x == arr[i])
            cnt++;
    }
    if (cnt)
        return {y, x};
    return {x, y};
}
int main()
{

    vector<int> arr = {1, 2, 4, 6, 3, 1};
    vector<int> ans = repeatedNumber(arr);
    for (auto x : ans)
        cout << x << " ";

    return 0;
}
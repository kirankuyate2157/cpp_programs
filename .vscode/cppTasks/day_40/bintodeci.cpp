#include <bits/stdc++.h>
using namespace std;
int binary_to_decimal(string str)
{
    // Code here.
    int ans = 0;
    int n = str.length();
    for (int i = n - 1; i >= 0; i--)
    {
        if (str[i] == '1')
            ans += 1 << (n - i - 1);
    }
    return ans;
}
int main()
{

    string s = "11001010";
    cout << binary_to_decimal(s);

    return 0;
}
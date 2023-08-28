#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int n=56;
    int n = 44;
    string s;
    for (int i = 0; n > 0; i++)
    {
        s += to_string(n % 2);
        n = n / 2;
    }
    // string k = "0010111111001";
    string k = "111111";
    cout << s << "\n"
         << k << " : ";
    int cnt = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (i >= k.length() || k[i] != s[i])
        {
            cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
void getprimefact(int n)
{
    vector<int> fact;
    if (n > 0)
        fact.push_back(1);
    int high = n;
    for (int i = 2; i * i < high; i++)
    {
        while (n % i == 0)
        {
            fact.push_back(i);
            n /= i;
        }
    }

    if (n != 0)
    {
        fact.push_back(n);
    }

    for (int ele : fact)
    {
        cout << ele << " ";
    }
    cout << " : ";
}

int main()
{
    long double pi = 3.14159265359;
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        cout << "Case #" << t << ": ";
        long int n, i = 1, cnt = 0;
        cin >> n;
        getprimefact(n);
        // while (i <= n)
        // {
        //     vector<int> fact;
        //     getprimefact(i, fact);
        //     int s = fact.size();
        //     int l = 0, r = s - 1;
        //     bool flg = true;
        //     if (s > 1)
        //     {
        //         while (l <= r)
        //         {
        //             if (fact[l] != fact[r])
        //             {
        //                 cout << " " << fact[l];
        //                 flg = false;
        //                 break;
        //             }
        //             l++;
        //             r--;
        //         }
        //     }
        //     if (flg || s == 1)
        //         cnt++;

        //     i++;
        // }
        // cout << cnt << " ";
        cout << "\n";

        t++;
    }
    return 0;
}
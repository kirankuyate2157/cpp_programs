#include <bits/stdc++.h>
using namespace std;
// printing following pattern
//       *
//      ***
//     *****
//    *******
//   *********
//  ***********
//   *********
//    *******
//     *****
//      ***
//       *

int main()
{
    int n = 5;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            cout << " ";
        }

        for (int j = 0; j <= 2 * i; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }
        cout << '\n';
    }
    for (int i = n; i >= 0; i--)
    {
        for (int j = 0; j <= n - i; j++)
        {
            cout << " ";
        }

        for (int j = 0; j <= 2 * i; j++)
        {
            cout << "*";
        }
        for (int j = 0; j <= n - i; j++)
        {
            cout << " ";
        }
        cout << '\n';
    }

    return 0;
}

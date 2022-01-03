#include <iostream>
using namespace std;
int main()
{
    int n = 25;
    for (int k = 0; k < n; k++)
    {
        for (int i = k; i <= n; i++)
        {
            for (int j = (5 * n) - i; j >= n; j--)
            {
                cout << "(";
            }
            for (int j = i; j > 0; j--)
            {
                cout << "-";
            }
            for (int j = 2; j <= i; j++)
            {
                cout << "-";
            }
            for (int j = (5 * n) - i; j >= n; j--)
            {
                cout << "(";
            }
            cout << "\n";
        }
        for (int i = n; i >= 0; i--)
        {
            for (int j = (5 * n) - i; j >= n; j--)
            {
                cout << "(";
            }
            for (int j = i; j > 0; j--)
            {
                cout << "-";
            }
            for (int j = 2; j <= i; j++)
            {
                cout << "-";
            }
            for (int j = (5 * n) - i; j >= n; j--)
            {
                cout << "(";
            }
            cout << "\n";
        }
        if (k % 2 == 1)
        {
            cout << "\n";
        }
    }
    return 0;
}
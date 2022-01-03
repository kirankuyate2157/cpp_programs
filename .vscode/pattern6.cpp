#include <iostream>
using namespace std;
int main()
{
    int n = 7;
    for (int i = 0; i < n; i++)
    {
        for (int j = n - i; j >= 0; j--)
        {
            cout << "  ";
        }
        for (int j = i; j > 0; j--)
        {
            cout << (char)('A' + j) << " ";
        }

        for (int j = 0; j <= i; j++)
        {
            cout << (char)('A' + j) << " ";
        }
        cout << "\n";
    }
    for (int i = n; i >= 0; i--)
    {
        for (int j = n - i; j >= 0; j--)
        {
            cout << "  ";
        }
        for (int j = i; j > 0; j--)
        {
            cout << (char)('A' + j) << " ";
        }

        for (int j = 0; j <= i; j++)
        {
            cout << (char)('A' + j) << " ";
        }
        cout << "\n";
    }
    return 0;
}
#include <iostream>
using namespace std;
int main()
{

    int n = 7;
    for (int i = 0; i < n + 3; i++)
    {
        cout << "# ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << " ";
        }

        cout << "*";

        for (int j = 0; j <= 2 * (n - i); j++)
        {
            if (i <= n / 2)
            {
                cout << " ";
            }
            else
            {
                cout << "_";
            }
        }

        cout << "*";

        for (int j = 0; j <= i; j++)
        {
            cout << " ";
        }
        cout << "\n";
    }
    for (int i = n; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << " ";
        }

        cout << "*";

        for (int j = 0; j <= 2 * (n - i); j++)
        {
            if (i < n / 2)
            {
                cout << "_";
            }
            else if (j == (2 * (n - i)) / 2)
            {
                cout << "-";
            }
            else
            {
                cout << " ";
            }
        }

        cout << "*";

        for (int j = 0; j <= i; j++)
        {
            cout << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i < n + 3; i++)
    {
        cout << "# ";
    }
}

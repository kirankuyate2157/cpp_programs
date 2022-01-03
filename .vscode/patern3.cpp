#include <iostream>
using namespace std;
int main()
{
    // diamoind shape pattrn
    int n = 7;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <i; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j <(n - i); j++)
        {
            cout << (n-j)<<" ";
        }
         for (int j =(n - i); j >=0; j--)
        {
            cout << (n-j)<<" ";
        }
        cout << "\n";
    }
 for (int i = n; i >=0; i--)
    {
        for (int j = 0; j <i; j++)
        {
            cout << "  ";
        }
        for (int j = 0; j <(n - i); j++)
        {
            cout << (n-j)<<" ";
        }
         for (int j =(n - i); j >=0; j--)
        {
            cout << (n-j)<<" ";
        }
        cout << "\n";
    }

    return 0;
}
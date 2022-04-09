#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        int r, c;
        cin >> r >> c;
        vector<vector<char>> mat((2 * r + 1), vector<char>((2 * c + 1), '@'));
        for (int i = 0; i <= 2 * r; i++)
        {
            for (int j = 0; j <= 2 * c; j++)
            {
                if (i <= 1 && j <= 1)
                {
                    mat[i][j] = '.';
                }
                else
                {
                    if (i % 2 == 0 && j % 2 != 0)
                        mat[i][j] = '-';
                    if (i % 2 != 0 && j % 2 == 0)
                        mat[i][j] = '|';
                    if (i % 2 == 0 && j % 2 == 0)
                        mat[i][j] = '+';
                    if (i % 2 != 0 && j % 2 != 0)
                        mat[i][j] = '.';
                }
            }
        }
        cout << "Case #" << t << ":\n";
        for (int i = 0; i <= 2 * r; i++)
        {
            for (int j = 0; j <= 2 * c; j++)
            {
                cout << mat[i][j];
            }
            cout << "\n";
        }
        t++;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        int n;
        cin >> n;
        vector<string> mat;

        for (int i = 0; i < 2 * n; i++)
        {
            string s;
            cin >> s;
            mat.push_back(s);
        }

        int cnt = 0;
        for (int i = 0; i < 2 * n; i += 2)
        {
            for (int j = 0; j < 2 * n; j++)
            {
                if (mat[i][j] == mat[i + 1][j])
                {
                    mat[i + 1][j] = 'k';
                    cnt++;
                }
            }
        }
        // for (int i = 0; i < 2 * n; i++)
        // {
        //     cout << mat[i] << "\n";
        // }
        if (cnt > n)
            cout << "Case #" << t << ": "
                 << "0\n";
        else
            cout << "Case #" << t << ": "
                 << cnt << "\n";
        t++;
    }
    return 0;
}

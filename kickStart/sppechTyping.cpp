#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, T = 0;
    cin >> t;
    while (T++ < t)
    {
        string I, P;
        cin >> I >> P;
        int i, j = 0, cnt = 0, n = I.length(), m = P.length();
        for (i = 0; i < I.length(); i++)
        {
            if (j >= m)
                break;
            while (I[i] != P[j] && j < m)
            {
                cnt++;
                j++;
            }
            if (I[i] == P[j])
                j++;
        }

        while (j < m)
        {
            cnt++;
            j++;
        }
        if ((i == j && cnt != 0) || i < n)
            cout << "Case #" << T << ": IMPOSSIBLE\n";
        else
            cout << "Case #" << T << ": " << cnt << "\n";
    }
    return 0;
}

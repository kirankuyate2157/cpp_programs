#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t=1, T;
    cin >> T;
    while (t <= T)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        // sort(v.begin(), v.end());
        vector<int> score(n, 0);
        int rate = 0, prev = 0;
        for (int i = 0; i < n; i++)
        {
            if (v[i] > prev)
            {
                rate++;
                prev = v[i];
            }else{
                prev = v[i];
            }
            score[i] = rate;
        }
        cout << "Case #" << t << ": ";
        for (int x : score)
            cout << x<<" ";
        cout << "\n";
        t++;
    }
    return 0;
}
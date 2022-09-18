#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int T, t = 1;
    cin >> T;
    while (t <= T)

    {

        int n;
        cin >> n;
        vector<pair<int, int>> arr;

        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            arr.push_back({x, i});
        }
        sort(arr.begin(), arr.end());
        // for (auto ele : arr)
        //     cout << "(" << ele.first << "," << ele.second << "), ";
        vector<int> ans(n, -1);
        // cout << "\n";
        int l = n - 1, r = n - 2;
        while (l >= 0 && r < n && r >= 0)
        {

            if (2 * arr[l].first >= arr[r].first && arr[l].second != arr[r].second)
            {
                ans[arr[l].second] = arr[r].first;
                l--;
                if (r < n - 1)
                    r++;
            }
            r--;
            if ((2 * arr[l].first < arr[r].first))
            {
                if (r == 0)
                    l--;
                if (r < n - 1)
                    r++;
            }
        }

        cout
            << "Case #" << t << ": ";
        for (int ele : ans)
            cout << ele << " ";
        cout << "\n";
        t++;
    }
    return 0;
}
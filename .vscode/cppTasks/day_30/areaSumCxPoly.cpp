#include <bits/stdc++.h>
using namespace std;
void polySum()
{
    int n;
    cin >> n;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    int a = v[0].first, b = v[0].second, sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x1 = v[i].first, y1 = v[i].second;
        int x2 = v[i + 1].first, y2 = v[i + 1].second;
        if ((i + 1) == n)
        {
            x2 = a, y2 = b;
        }
        int b = (x1 * y2) - (x2 * y1); if (b % 2 == 0)
        {
            sum += b;
        }

        // cout << sum << "\n";
    }

    sum = abs(sum);
    // sum = sum % 998244353;
    cout << sum << "  <-- \n";
    // for(auto x:v)cout<<"("<<x.first<<","<<x.second<<") ,";
    // cout<<"\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        polySum();
    }

    return 0;
}
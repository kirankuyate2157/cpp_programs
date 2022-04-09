#include <bits/stdc++.h>
using namespace std;
#define ll long long
class Printer
{
public:
    int c, m, y, k;
};

void colors(int t)
{
    ll arr[3][4];
    vector<ll> v(4, 1000000);
    cout << "Case #" << t << ": ";
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 4; j++)
        {
            ll b;
            cin >> b;
            arr[i][j] = b;
        }

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 3; j++)
            v[i] = min(v[i], arr[j][i]);

    ll sum = 0;
    for (auto x : v)
        sum += x;
    if (sum < 1e6)
    {
        cout << "IMPOSSIBLE";
    }
    // cout << "hii";
    else
    {
        ll bd = 1e6;
        for (int i = 0; i < 4; i++)
        {
            if (v[i] > bd)
            {
                cout << bd << " ";
                bd = 0;
            }
            else
            {
                cout << v[i] << " ";
                bd -= v[i];
            }
        }
    }
}

int main()
{
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        colors(t);
        cout << "\n";
        t++;
    }

    return 0;
}

/*
int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        Printer p;
        vector<Printer> arr(3);
        int mm, cm, ym, km;
        cm = mm = ym = km = INT_MAX;
        int ans[4];

        for (int i = 0; i < 3; i++)
        {
            cin >> arr[i].c;
            cin >> arr[i].m;
            cin >> arr[i].y;
            cin >> arr[i].k;
            ans[0] = cm = min(cm, arr[i].c);
            ans[1] = mm = min(mm, arr[i].m);
            ans[2] = ym = min(ym, arr[i].y);
            ans[3] = km = min(km, arr[i].k);
        }
        int n = 4;
        // sort(ans, ans + n);
        int total = cm + mm + ym + km;
        int rem = total - 1000000;
        cout<<rem<<"\n";

        int final = 0;
        for (int c : ans){
            final += c;
            cout << c << " ";
        }
        cout << "\n";
        cout << final << " \n";
        // cout << "finall :" << cm << " " << mm << " " << ym << " " << km << "\n";
        t++;
    }

*/
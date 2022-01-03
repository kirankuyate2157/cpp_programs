#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int blue, black, red;
    cin >> red >> black >> blue;
    if (blue + black < red || blue < 1 || black < 1)
    {
        cout << "-1\n";
    }
    else
    {
        string ans;
        vector<pair<int, int>> edges;
        ans += "bb";
        edges.push_back({1, 2});
        blue--;
        black--;
        int cur_nodes = 3;
        while (black--){
            edges.push_back({1, cur_nodes++});
        }
        while (blue--){
            edges.push_back({2, cur_nodes++});
        }
        int B_node = 1;
        ans+="r";
        while (red--){
            edges.push_back({B_node++, cur_nodes++});
        }
        // cout << ans << " ->   ";
        cout<<edges.size()<<"\n";
        // for (pair<int,int>items : edges){
        //     cout << "(" << items.first << "," << items.second << ") , ";
        // }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
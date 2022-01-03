#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll int n;
    cin >> n;
    int i = 1;
    vector<int> v;
    set<int>s;
    while (i <= sqrt(n))
    {
        s.insert(i*i);
        i++;
    }
    i = 1;
    while (i <= cbrt(n))
    {
        s.insert(i*i*i);
        i++;
    }
    
    // for(auto x:s){
       
        // 
    //     cout<<x<<" ";
    // }
    cout<< s.size() << "\n";
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
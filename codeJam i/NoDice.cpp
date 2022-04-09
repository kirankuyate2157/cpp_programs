#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int cnt=0;
        sort(v.begin(), v.end());
        for(auto x:v){
            if(x>cnt){
                // cout<<"("<<x<<" - "<<cnt<<"),";
                cnt++;
            }
        }
        cout << "Case #" << t << ": "<<cnt<<"\n";


        t++;
    }

    return 0;
}
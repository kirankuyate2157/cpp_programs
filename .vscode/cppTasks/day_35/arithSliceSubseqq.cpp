#include <bits/stdc++.h>
using namespace std;

int sol(vector<int> arr)
{
    int ans = 0;
    vector<unordered_map<long long, int>> mp(arr.size());
    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            long long diff = (long long)arr[i] - arr[j];

            int cnt = mp[j].count(diff) ? mp[j][diff] : 0;
            mp[i][diff] += cnt + 1;
            ans += cnt;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {2, 4, 6, 8, 10};
    cout << "common diff subsequence count :" << sol(arr) << endl;
    return 0;
}
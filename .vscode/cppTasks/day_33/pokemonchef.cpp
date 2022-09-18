#include <bits/stdc++.h>
using namespace std;
#define 11 Long Long
void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), brr(n), temp1(n), temp2(n);
    for (int i = 0; i < n; i++)
    {
    }
    cin >> arr[i];
    temp1[i] = arr[i];
    for (int i = 0; i < n; i++)
    {
        cin >> brr[i];
        temp2[i] = brr[i];
    }
    sort(temp1.begin(), temp1.end());
    sort(temp2.begin(), temp2.end());
    temp1.erase(unique(temp1.begin(), temp1.end()), temp1.end());
    temp2.erase(unique(temp2.begin(), temp2.end()), temp2.end());
    for (int i = 0; i < n; i++)
    {
        arr[i] = lower_bound(temp1.begin(), temp1.end(), arr[i]) - temp1.begin();
    }

#include < bits / stdc ++ . h >
    using namespace std;
#define 11 Long Long
    void solve()
    {
        int n;
        cin >> n;
        vector<int> arr(n), brr(n), temp1(n), temp2(n);
        for (int i = 0; i < n; i++)
        {
        }
        cin >> arr[i];
        temp1[i] = arr[i];
        for (int i = 0; i < n; i++)
        {
            cin >> brr[i];
            temp2[i] = brr[i];
        }
        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());
        temp1.erase(unique(temp1.begin(), temp1.end()), temp1.end());
        temp2.erase(unique(temp2.begin(), temp2.end()), temp2.end());
        for (int i = 0; i < n; i++)
        {
            arr[i] = lower_bound(temp1.begin(), temp1.end(), arr[i]) - temp1.begin();
        }

#include < bits / stdc ++ . h >
        using namespace std;
#define 11 Long Long
        void solve()
        {
            int n;
            cin >> n;
            vector<int> arr(n), brr(n), temp1(n), temp2(n);
            for (int i = 0; i < n; i++)
            {
            }
            cin >> arr[i];
            temp1[i] = arr[i];
            for (int i = 0; i < n; i++)
            {
                cin >> brr[i];
                temp2[i] = brr[i];
            }
            sort(temp1.begin(), temp1.end());
            sort(temp2.begin(), temp2.end());
            temp1.erase(unique(temp1.begin(), temp1.end()), temp1.end());
            temp2.erase(unique(temp2.begin(), temp2.end()), temp2.end());
            for (int i = 0; i < n; i++)
            {
                arr[i] = lower_bound(temp1.begin(), temp1.end(), arr[i]) - temp1.begin();
            }

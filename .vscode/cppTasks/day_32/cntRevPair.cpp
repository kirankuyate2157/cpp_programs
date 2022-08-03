#include <bits/stdc++.h>
using namespace std;
int merge(vector<int> &arr, int l, int mid, int r)
{
    int inv = 0;
    int j = mid + 1;
    for (int i = l; i <= mid; i++)
    {
        while (j <= r && arr[i] > 2 * (long)arr[j])
            j++;

        inv += j - (mid + 1);
    }
    vector<int> ans;
    int i = l;
    j = mid + 1;
    while (j <= r && i <= mid)
    {
        if (arr[i] <= arr[j])
            ans.push_back(arr[i++]);
        else
            ans.push_back(arr[j++]);
    }
    while (j <= r)
        ans.push_back(arr[j++]);
    while (i <= mid)
        ans.push_back(arr[i++]);
    for (int i = l; i <= r; i++)
        arr[i] = ans[i - l];
    return inv;
}

int mergesort(vector<int> &arr, int l, int r)
{
    if (l >= r)
        return 0;
    int mid = (l + r) / 2;
    int inv = mergesort(arr, l, mid);
    inv += mergesort(arr, mid + 1, r);
    inv += merge(arr, l, mid, r);
    return inv;
}
int revPair(vector<int> arr, int n)
{
    return mergesort(arr, 0, n - 1);
}
int main()
{
    vector<int> arr = {2, 4, 3, 5, 1};
    int n = arr.size();
    cout << revPair(arr, n);

    return 0;
}
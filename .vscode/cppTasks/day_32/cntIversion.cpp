#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &arr, int left, int mid, int right)
{
    vector<int> temp(arr);
    int inv_count = 0;
    int i = left;
    int j = mid;
    int k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}
int merge_Sort(vector<int> &arr, int left, int right)
{
    int mid, inv_count = 0;
    if (right > left)
    {
        mid = (left + right) / 2;

        inv_count += merge_Sort(arr, left, mid);
        inv_count += merge_Sort(arr, mid + 1, right);

        inv_count += merge(arr, left, mid + 1, right);
    }
    return inv_count;
}
int main()
{
    vector<int> arr = {5, 3, 2, 1, 4};
    cout << merge_Sort(arr, 0, arr.size() - 1);

    return 0;
}
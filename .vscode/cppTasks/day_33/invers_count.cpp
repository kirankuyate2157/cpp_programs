#include <bits/stdc++.h>
using namespace std;

long long int merge(long long arr[], long long temp[], long long l, long long mid, long long r)
{
    long long int cnt = 0;
    long long i = l;
    long long j = mid;
    long long k = l;
    while ((i <= mid - 1) && (j <= r))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            cnt = cnt + (mid - i);
        }
    }
    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= r)
        temp[k++] = arr[j++];

    for (i = l; i <= r; i++)
        arr[i] = temp[i];

    return cnt;
}

long long int merge_sort(long long arr[], long long temp[], long long l, long long r)
{
    long long int cnt = 0;
    long long mid;
    if (r > l)
    {
        mid = (l + r) / 2;
        cnt += merge_sort(arr, temp, l, mid);
        cnt += merge_sort(arr, temp, mid + 1, r);

        cnt += merge(arr, temp, l, mid + 1, r);
    }
    return cnt;
}

int main()
{
    long long arr[] = {5, 3, 2, 1, 4};
    long long n = 5;
    long long temp[n];
    long long ans = merge_sort(arr, temp, 0, n - 1);
    cout << "The total inversions are " << ans << endl;

    return 0;
}
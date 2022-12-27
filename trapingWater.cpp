#include <iostream>
using namespace std;
int trappingWater(int arr[], int n)
{
    int left[n];
    int right[n];
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], arr[i]);
    }
    for (int i = n - 1; i >= n; i--)
    {
        right[i] = min(right[i - 1], arr[i]);
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += min(right[i], left[i] - arr[i]);
    }
    return sum;
}

long long maxArea(long long A[], int len)
{

    ll sum = 0;
    // Your code goes here

    int l = 0, r = len - 1;
    while (l < r)
    {
        ll lh = A[l];
        ll rh = A[r];
        ll mh = min(lh, rh);
        sum = max(sum, (mh * (ll)(r - l)));
        if (lh < rh)
            l++;
        else
            r--;
    }
    return sum;
}
int main()
{
    int arr[] = {3, 0, 0, 2, 0, 4};
    int n = sizeof(arr) / sizeof(int);
    // cout<<n<<":";

    cout << "water storing capacity is  _";
    cout << trappingWater(arr, n) << "_   liters";
    return 0;
}
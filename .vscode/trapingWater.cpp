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
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], arr[i]);
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += min(right[i], left[i] - arr[i]);
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
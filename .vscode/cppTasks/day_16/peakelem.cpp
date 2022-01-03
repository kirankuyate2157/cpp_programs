#include <iostream>
using namespace std;
int binarySearch(int arr[], int l, int r, int n)
{

    int mid = l + (r - l) / 2;

    if ((mid == 0 || arr[mid - 1] <= arr[mid]) &&
        (mid == n - 1 || arr[mid + 1] <= arr[mid]))
        return mid;
    else if (mid > 0 && arr[mid - 1] > arr[mid])
        return binarySearch(arr, l, (mid - 1), n);

    else
        return binarySearch(arr, (mid + 1), r, n);
}

int peakElement(int arr[], int n)
{
    if (n <= 0)
    {
        return 0;
    }

    return binarySearch(arr, 0, n - 1, n);
}


int main()
{
    int arr[] = {
        1,
        2,
        3,
        70,
        5,
        6,
        7,
    };
    int n = sizeof(arr) / sizeof(int);
    cout<<n<<"\n";
   cout<< peakElement(arr, n);

    return 0;
}
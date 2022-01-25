#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

void heafify(int arr[], int cur, int n)
{
    int large = cur;
    int left = (2 * cur) + 1;
    int right = (2 * cur) + 2;
    if (left < n && arr[large] > arr[left])
    {
        large = left;
    }
    if (right < n && arr[large] > arr[right])
    {
        large = right;
    }
    if (large != cur)
    {
        int temp = arr[large];
        arr[large] = arr[cur];
        arr[cur] = temp;
        heafify(arr, large, n);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = (n + 1) / 2; i >= 0; i--)
    {
        heafify(arr, i, n);
    }
    for (int i = 0; i < n; i++)
    {
        int temp = arr[0];
        arr[0] = arr[n - i - 1];
        arr[n - i - 1] = temp;
        print(arr, n);
       heafify(arr, 0, n - i - 1);
    }
}

int main()
{
    int arr[] = {6, 9, 2, 11, 1, 23, 5, 9};
    int n = sizeof(arr) / sizeof(int);
    heapSort(arr, n);
    print(arr, n);
    return 0;
}
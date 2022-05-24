#include <bits/stdc++.h>
using namespace std;
void heapify(int arr[], int i, int n)
{
    int largest = i;
    if ((2 * i + 1) < n && arr[largest] < arr[2 * i + 1])
    {
        largest = (2 * i + 1);
    }
    if ((2 * i + 2) < n && arr[largest] < arr[2 * i + 2])
    {
        largest = (2 * i + 2);
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, largest, n);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = (n - 1) / 2; i >= 0; i--)
    {
        heapify(arr, i, n);
    }
    for (int i = 0; i < n; i++)
    {
        swap(arr[n - i - 1], arr[0]);
        heapify(arr, 0, n - i - 1);
    }
}
int main()
{
    int arr[] = {4, 12, 67, 3, 19, 57, 23, 33, 2, 8, 9};
    int n = sizeof(arr) / sizeof(int);
    heapSort(arr, n);
    for (int x : arr)
        cout << x << " ";
    return 0;
}
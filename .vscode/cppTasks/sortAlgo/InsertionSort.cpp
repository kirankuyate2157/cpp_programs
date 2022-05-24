#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{

    for (int i = 0; i < n; i++)
    {
        int ele = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] >= ele)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = ele;
    }
}

int main()
{
    int arr[] = {4, 7, 1, 8, 2, 44, 23, 89, 11, 457};
    int n = sizeof(arr) / sizeof(int);
    insertionSort(arr, n);
    for (int x : arr)
    {
        cout << x << " ";
    }
    return 0;
}
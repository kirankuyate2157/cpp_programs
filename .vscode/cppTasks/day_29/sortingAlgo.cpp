#include <bits/stdc++.h>
using namespace std;
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            if (arr[j + 1] > arr[j])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    print(arr, n);
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++)
    {

        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        swap(arr[min_idx], arr[i]);
    }
    print(arr, n);
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int cur = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] >cur)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = cur;
    }
    print(arr, n);
}

int main()
{
    int arr[] = {6, 4, 7, 9, 223, 1, 5, 7, 9, 23, 12, 67, 23, 98, 22, 33, 12, 7};
    int n = sizeof(arr) / sizeof(int);
    // bubbleSort(arr, n);
    // selectionSort(arr, n);
    insertionSort(arr,n);
    return 0;
}
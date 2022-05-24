// #include<bits/stdc++.h>
#include <iostream>
using namespace std;
void bubleSort(int arr[], int n)
{
    bool well = false;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                well = true;
            }
        }
        if (well == false)
            break;
    }
}
int main()
{
    int arr[] = {45, 5, 2424, 22, 55, 56, 45, 2, 88, 12, 1};
    int n = sizeof(arr) / sizeof(int);
    bubleSort(arr, n);
    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}
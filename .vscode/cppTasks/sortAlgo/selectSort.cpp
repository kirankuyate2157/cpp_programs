
#include <iostream>
using namespace std;
void selectSort(int arr[], int n)
{
    int min_index = 0;
    for (int i = 0; i < n - 1; i++)
    {
        min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        if (min_index != i)
            swap(arr[i], arr[min_index]);
    }
}
int main()
{
    int arr[] = {8, 45, 245, 9, 23, 61, 556, 4, 23};
    int n = sizeof(arr) / sizeof(int);
    selectSort(arr, n);
    for (int x : arr)
        cout << x << " ";

    return 0;
}
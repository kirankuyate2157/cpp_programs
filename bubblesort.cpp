#include <iostream>
using namespace std;


void bubbleSort(int arr[], int n)
{                               `

    for (int i = 0; i < n - 1; i++)

        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {

                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
}           ```

int main()
{
    int arr[] = {3, 9, 1, 4, 7, 10, 45, 7, 10};
    int n = sizeof(arr) / sizeof(int);
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
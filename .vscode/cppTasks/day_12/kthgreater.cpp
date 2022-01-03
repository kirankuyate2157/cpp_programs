#include <iostream>
using namespace std;

int kthgreater(int arr[], int n, int k)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < (n - i - 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return (arr[n - k]);
}


int main()
{
    int n = 7;
    int arr[] = {8, 7, 2, 1, 11, 5, 3};
    int k = 1;
    cout << k << "th greatest number is  ";
    cout << kthgreater(arr, n, k);

    return 0;
}
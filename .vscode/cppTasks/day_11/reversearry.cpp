#include <iostream>
using namespace std;


// reverse the given array 
int reverse(int arr[],int n)
{
    int start = 0;
    int end = n - 1;
    while (start < end)
    {                                         //swaping values 
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(int);          //length of array 

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ",";                 // priting normal array 
    }
    cout << "\n";
    reverse(arr,n);                        // calling reverse function for reversing the array
    cout << " n  =" << n << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ",";                  //pprinting reverse  array 
    }

    return 0;
    
}
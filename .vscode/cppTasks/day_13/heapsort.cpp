#include <iostream>
using namespace std;


void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = (2 * i + 1);
    int r = 2 * i + 2;
    while (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    while (r <n && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}



void heapsort(int arr[], int n)
{
    for (int i = n/2-1; i >= 0; i--)
    { //sorting tree
        heapify(arr, n, i);
    }
    for (int i = n-1; i>= 0; i--)
    {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        heapify(arr, n, 0);
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main()
{
    
    int arr[] = {6, 8, 23, 1, 5, 7, 11, 2};
    int n=sizeof(arr)/sizeof(int);
    heapsort(arr, n);
    return 0;
}
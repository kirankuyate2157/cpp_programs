#include <bits/stdc++.h>

using namespace std;
void merge1(int arr1[], int arr2[], int n, int m)
{
    // code here
    int i, k;
    for (i = 0; i < n; i++)
    {
        // take first element from arr1
        // compare it with first element of second array
        // if condition match, then swap
        if (arr1[i] > arr2[0])
        {
            int temp = arr1[i];
            arr1[i] = arr2[0];
            arr2[0] = temp;
        }

        // then sort the second array
        // put the element in its correct position
        // so that next cycle can swap elements correctly
        int first = arr2[0];
        // insertion sort is used here
        for (k = 1; k < m && arr2[k] < first; k++)
        {
            arr2[k - 1] = arr2[k];
        }
        arr2[k - 1] = first;
    }
}

void merge2(int ar1[], int ar2[], int n, int m)
{
    // code here
    int gap = ceil((float)(n + m) / 2);
    while (gap > 0)
    {
        int i = 0;
        int j = gap;
        while (j < (n + m))
        {
            if (j < n && ar1[i] > ar1[j])
            {
                swap(ar1[i], ar1[j]);
            }
            else if (j >= n && i < n && ar1[i] > ar2[j - n])
            {
                swap(ar1[i], ar2[j - n]);
            }
            else if (j >= n && i >= n && ar2[i - n] > ar2[j - n])
            {
                swap(ar2[i - n], ar2[j - n]);
            }
            j++;
            i++;
        }
        if (gap == 1)
        {
            gap = 0;
        }
        else
        {
            gap = ceil((float)gap / 2);
        }
    }
}
int main()
{
    int arr1[] = {1, 4, 7, 8, 10};
    int arr2[] = {2, 3, 9};
    cout << "Before merge:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    merge2(arr1, arr2, 5, 3);
    cout << "After merge:" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << arr2[i] << " ";
    }
}
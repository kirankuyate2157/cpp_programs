#include <bits/stdc++.h>
using namespace std;

void merge(int v[], int l, int mid, int r) // merging two array or vectores
{
    vector<int> first;             // first array part
    vector<int> second;            // second array part
    for (int i = l; i <= mid; i++) // Inserting first  half elment from origiunal vectore
    {
        first.push_back(v[i]);
    }
    for (int i = mid + 1; i <= r; i++) // inserting second half from original vector
    {
        second.push_back(v[i]);
    }
    int n = first.size(); // takin size of both seprated vectores
    int m = second.size();
    int i = 0, j = 0, k = l; // inserting element form both seprated vectors  into original vectoir by  sortinbg order
    while (i < n && j < m)
    {
        if (first[i] < second[j])
        {
            v[k] = first[i];
            i++;
            k++;
        }
        else
        {
            v[k] = second[j];
            k++;
            j++;
        }
    }

    while (i < n)
    {
        v[k] = first[i];
        k++;
        i++;
    }
    while (j < m)
    {
        v[k] = second[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l >= r)
        return;

    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
}

int main()
{
    int arr[] = {4, 7, 12, 89, 12, 53, 313, 54, 6, 75, 75, 6646, 4, 64, 667, 313, 6};
    int n = sizeof(arr) / sizeof(int);
    cout << "Merging1";
    mergeSort(arr, 0, n - 1);
    for (int x : arr)
    {
        cout << x << " ";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &v, int l, int mid, int r) // merging two array or vectores
{
    int c = 0;
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
            c++;
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
    return c;
}
int mergeSort(vector<int> &v, int l, int r) // merging two part of vector of original vector
{
    int c = 0;
    if (l >= r) // if vector is empty or one size then  directolly return
    {
        return 0;
    }
    int mid = (l + r) / 2;         /// finding mid index  point of vector
    c += mergeSort(v, l, mid);     // giving first half  for merge sort
    c += mergeSort(v, mid + 1, r); // giving secind half of the vector for the merge sort
    c += merge(v, l, mid, r);
    return c; // and merging both half parts of vectore
}

int main()
{
    vector<int> v = {5, 3, 2, 1, 4}; // declaring vector
    int n = v.size();                // size of vector

    cout << mergeSort(v, 0, n - 1) << " \n"; // cal;ling merge sorting
    for (int i = 0; i < n; i++)              /// print ing vector
    {
        cout << v[i] << " ";
    }
    return 0;
}

/*

Output  --->

PS F:\Cpp_programes> cd "f:\Cpp_programes\.vscode\cppTasks\day_1\" ; if ($?) { g++ sortlist.cpp -o sortlist } ; if ($?) { .\sortlist }
2 3 4 5 7 8 9 10 11 17

*/

// You have given a N elements.5, 2, 8, 7, 2, 9, 7, 8, 10, 67, 10, 67 You have to find elements which occurs only ones in the.Given list.
// In given list of elements occurs at one these are only two.
// You have to give me the these two elements from given list in the array or list.In ascending order....

// 5, 2, 8, 7, 2, 9, 7, 8, 10, 67, 10, 67
// 2,2,5,7,7,8,8,9,10,10......
#include <bits/stdc++.h>
using namespace std;

void singltwo(int arr[], int n)
{
    int ans[2];
    sort(arr, arr + n);
    int i = 0,j=0;
    while (i < n)
    {
        if (arr[i] == arr[i + 1])
        {
            i += 2;
        }
        else
        {
            ans[j++] = arr[i];
            i++;
        }
    }
    for (int x : ans)
    {
        cout << x << " ";
    }
}
int main()
{
    int arr[] = {5, 2, 8, 7, 2, 9, 7, 8, 10, 67, 10, 67};
    int n = sizeof(arr) / sizeof(int);
    singltwo(arr, n);

    return 0;
}
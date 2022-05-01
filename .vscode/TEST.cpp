
#include <bits/stdc++.h>

using namespace std;
void RepeatMiss(vector<int> arr)
{
    int n = sizeof(arr) / sizeof(int);
    int A, B;
    int vis[n + 1] = {0};
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
        if (arr[i] == arr[i + 1])
            A = arr[i];

        if (arr[i] != i + 1)
        {
            B = arr[i + 1];
            cout << "kk";
        }
    }
    cout << "\n"
         << A << " " << B << " ";
}

int main()
{
    vector<int> arr;
    arr = {3, 1, 2, 5, 4, 6, 7, 5};
    RepeatMiss(arr);
}
#include <bits/stdc++.h>
using namespace std;

void splitArr(vector<int> &arr)
{
    int n = arr.size();
    vector<int> subArr(n);
    int sum = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] = i||arr[i]<0)
            sum -= arr[i];
        else
            sum += arr[i];
    }
    cout << sum;
    cout << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        splitArr(arr);
    }

    return 0;
}
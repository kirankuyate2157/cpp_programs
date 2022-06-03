#include <bits/stdc++.h>
using namespace std;
bool ispresent(vector<vector<int>> &arr, int x)
{
    int n = arr.size();
    int m = arr[0].size();
    int l = 0;
    int r = n * m - 1;
    while (r >= l)
    {
        int mid = (l + (r - l) / 2);
        if (arr[mid / m][mid % m] == x)
            return true;
        if (arr[mid / m][mid % m] < x)
            l = mid + 1;
        else
            r = mid - 1;
        cout << ". ";
    }
    return false;
}
int main()
{
    vector<vector<int>> arr = {{1, 3, 5, 7},
                               {10, 11, 16, 20},
                               {23, 30, 34, 60}};
    cout << ispresent(arr, 60);
    cout << "--------------------------------";
    return 0;
}
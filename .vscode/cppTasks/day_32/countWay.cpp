#include <bits/stdc++.h>
using namespace std;

int cntway(vector<vector<int>> arr, int n, int i, int j)
{
    if (i == n - 1 && j == n - 1)
        return 1;
    if (i >= n || j >= n || arr[i][j] == 0)
        return 0;
    return cntway(arr, n, i + 1, j) + cntway(arr, n, i, j + 1);
}

int main()
{
    vector<vector<int>> arr = {{1, 1, 0, 1},
                               {1, 1, 1, 1},
                               {1, 1, 1, 1},
                               {0, 1, 1, 1}};
    cout << "ways are :" << cntway(arr, 4, 0, 0) << endl;
    return 0;
}

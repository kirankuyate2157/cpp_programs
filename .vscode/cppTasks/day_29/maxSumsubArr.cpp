#include <bits/stdc++.h>
using namespace std;
int maxSubArr(vector<int> arr)
{
    int n = arr.size();
    if (n == 1)
        return arr[0];
    int max_sum = arr[0], s = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > max_sum)
            max_sum = sum;
        if (sum < 0)
        {
            sum = 0;
            s = i + 1;
        }
    } 
    return max_sum;

}
int main()
{

    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> arr2 = {5, 4, -1, 7, 8};

    cout << maxSubArr(arr2);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
vector<int> lar3(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans;
    int cnt1 = 0, cnt2 = 0, num1 = -1, num2 = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num1)
        {
            cnt1++;
        }
        else if (arr[i] == num2)
        {
            cnt2++;
        }
        else if (cnt1 == 0)
        {
            num1 = arr[i];
        }
        else if (cnt2 == 0)
        {
            num2 = arr[i];
        }
        else
        {
            cnt1--;
            cnt2--;
        }

        if (cnt1 > n / 3)
            ans.push_back(num1);
        if (cnt2 > n / 3)
            ans.push_back(num2);
    }
    return ans;
}
int main()
{

    vector<int> arr = {1, 4, 1, 8, 1, 2, 4, 4, 1, 8, 4};
    vector<int> ans = lar3(arr);
    for (int x : ans)
        cout << x << " ";

    return 0;
}
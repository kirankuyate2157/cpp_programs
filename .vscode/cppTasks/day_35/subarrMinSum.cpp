#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int sumSubarrayMins(vector<int> &arr)
    {

        int n = arr.size();
        stack<int> st1, st2;
        vector<int> suffix(n), preffix(n);
        for (int i = 0; i < n; i++)
        {
            suffix[i] = n - i - 1;
            preffix[i] = i;
        }
        for (int i = 0; i < n; i++)
        {
            while (!st1.empty() && arr[i] < arr[st1.top()])
            {
                suffix[st1.top()] = i - st1.top() - 1;
                st1.pop();
            }
            st1.push(i);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st2.empty() && arr[i] <= arr[st2.top()])
            {
                preffix[st2.top()] = st2.top() - i - 1;
                st2.pop();
            }
            st2.push(i);
        }
        int ans = 0;
        int m = 1e9 + 7;
        for (int i = 0; i < n; i++)
        {

            long long prod = (preffix[i] + 1) * (suffix[i] + 1) % m;
            prod = (prod * arr[i]) % m;
            ans = (ans + prod) % m;

            // ans%=m;
        }

        return ans;
    }
};
int main()
{
    vector<int> arr = {2, 3, 5, 1, 7, 12, 2, 2, 4, 5, 6};
    Solution obj;
    cout << obj.sumSubarrayMins(arr) << endl;
    return 0;
}
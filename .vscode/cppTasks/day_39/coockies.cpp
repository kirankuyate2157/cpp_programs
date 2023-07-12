#include <bits/stdc++.h>
using namespace std;
// started now...
class Solution
{
public:
    void giveme(int ind, const vector<int> &cookies, vector<int> &gotC, int k, int &ans)
    {
        int n = cookies.size();

        if (ind == n)
        {
            int currMax = INT_MIN;
            for (int i = 0; i < k; i++)
            {
                currMax = max(currMax, gotC[i]);
            }

            ans = min(ans, currMax);
            return;
        }

        for (int i = 0; i < k; i++)
        {
            gotC[i] += cookies[ind];

            giveme(ind + 1, cookies, gotC, k, ans);

            gotC[i] -= cookies[ind];
        }
    }

    int distributeCookies(vector<int> &cookies, int k)
    {
        int ans = INT_MAX;
        vector<int> gotC(k, 0);

        giveme(0, cookies, gotC, k, ans);
        return ans;
    }
};

int main()
{

    Solution obj;
    vector<int> cookies = {8, 15, 10, 20, 8};
    int k = 2;
    cout << " ans : " << obj.distributeCookies(cookies, k);
}
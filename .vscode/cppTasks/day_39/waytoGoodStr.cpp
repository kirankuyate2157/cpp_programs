#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const int M = 1e9 + 7;
    int countGoodStrings(int low, int high, int zero, int one)
    {
        vector<int> t(high + 1, 0);

        t[0] = 1;
        for (int i = 1; i <= high; i++)
        {
            if (i - zero >= 0)
                t[i] = (t[i] % M + t[i - zero] % M) % M;

            if (i - one >= 0)
                t[i] = (t[i] % M + t[i - one] % M) % M;
        }
        int ans = 0;
        for (int i = low; i <= high; i++)
        {
            ans = (ans % M + t[i] % M) % M;
        }
        return ans;
    }
};

int main()
{
    Solution obj;
    cout << "Number of diff good str : " << obj.countGoodStrings(3, 3, 1, 1);

    return 0;
}
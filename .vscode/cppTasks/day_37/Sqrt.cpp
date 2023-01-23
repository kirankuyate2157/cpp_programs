#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mySqrt(int x)
    {
        double ans = 0, rem = 0, divisor = 0;
        long l = 1, r = x, mid;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (mid == (x / mid))
            {
                return mid;
            }
            else if (mid < x / mid)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        cout << l << " " << mid << " " << r;
        return r;
    }
};

int main()
{
    int x = 18;
    Solution obj;
    cout << "Square root of " << x << " is : " << obj.mySqrt(x);
}
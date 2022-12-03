#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int divide(int Q, int div)
    {
        if (Q == INT_MIN && div == -1)
            return INT_MAX;
        if (Q == INT_MIN && div == 1)
            return INT_MIN;

        unsigned int result = 0;
        bool sign = (Q < 0 == div < 0);

        if (abs(Q) == abs(div))
            return sign ? 1 : -1;

        unsigned int a = abs(Q);
        unsigned int b = abs(div);

        while (a >= b)
        {
            short k = 0;
            while (a > (b << (k + 1)))
                k++;

            result += 1 << k;
            a -= b << k;
        }
        // if (result == (1 << 31) and sign)
        //     return INT_MAX;
        return sign ? result : -result;
    }
};
int main()
{
    int a = 342, b = 5;
    Solution obj;
    cout << obj.divide(a, b) << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countDigits(int num)
    {
        int cnt = 0;
        int temp = num;
        map<int, int> mp;
        while (num)
        {
            int x = num % 10;
            mp[x]++;

            num /= 10;
        }
        for (auto x : mp)
        {
            if (temp % x.first == 0)
            {
                cnt += x.second;
            }
        }
        return cnt;
    }
};

int main()
{
    Solution obj;
    cout << "number of digit in 7446864 in this num are : " << obj.countDigits(7446864);
    return 0;
}
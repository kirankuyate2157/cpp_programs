#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> ans;
        for (auto x : asteroids)
        {

            while (!ans.empty() && x < 0 && ans.back() > 0)
            {
                int sum = x + ans.back();
                if (sum < 0)
                {
                    ans.pop_back();
                }
                else if (sum > 0)
                {
                    x = 0;
                }
                else
                {
                    x = 0;
                    ans.pop_back();
                }
            }

            if (x != 0)
                ans.push_back(x);
        }
        return ans;
    }
};
int main()
{
    // Input: asteroids = [5,10,-5]
    //  Output: [5,10]
    //  Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
    vector<int> astroids = {5, 10, -5};
    Solution obj;
    astroids = obj.asteroidCollision(astroids);
    cout << "safe Asteroids : ";
    for (auto x : astroids)
    {
        cout << x << ",";
    }
    return 0;
}
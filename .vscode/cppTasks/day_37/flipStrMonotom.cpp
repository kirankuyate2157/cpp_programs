#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFlipsMonoIncr(string S)
    {
        int count_flip = 0, count_one = 0;
        for (auto i : S)
        {
            // keep track of all one (we will use count_one in else condition if we need)
            // if we want flip one into 0
            if (i == '1')
                count_one++;
            else
            {
                count_flip++;
                count_flip = min(count_flip, count_one);
            }
        }
        return count_flip;
    }
};

int main()
{
    string s = "010110";
    Solution obj;
    cout << "The minimum number of flips to make s monotone increasing : " << obj.minFlipsMonoIncr(s);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        vector<bool> arr;
        int great = 0;
        for (auto x : candies)
        {
            if (x > great)
            {
                great = x;
            }
        }
        int diff = great - extraCandies;
        for (auto x : candies)
        {
            arr.push_back(x >= diff);
        }

        return arr;
    }
};
int main()
{

    vector<int> candies = {2, 3, 5, 1, 3};
    int extraCandies = 3;
    Solution obj;
    cout << " greatest number of candies among all the kids : ";
    vector<bool> ans = obj.kidsWithCandies(candies, extraCandies);
    for (auto x : ans)
    {
        cout << x << ",";
    }
}
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static bool comp(pair<int, int> a, pair<int, int> b)
    {
        return (b.second - b.first) >= (a.second - a.first);
    }

    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
    {
        int n = rocks.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            capacity[i] = capacity[i] - rocks[i];
        }
        sort(capacity.begin(), capacity.end());
        for (int i = 0; i < n; i++)
        {
            if (capacity[i] == 0)
            {
                cnt++;
                continue;
            }
            if (capacity[i] <= additionalRocks)
            {
                additionalRocks -= capacity[i];
                cnt++;
            }
        }
        return cnt;
    }
};
int main()
{
    vector<int> capacity = {54, 18, 91, 49, 51, 45, 58, 54, 47, 91, 90, 20, 85, 20, 90, 49, 10, 84, 59, 29, 40, 9, 100, 1, 64, 71, 30, 46, 91};
    vector<int> rocks = {14, 13, 16, 44, 8, 20, 51, 15, 46, 76, 51, 20, 77, 13, 14, 35, 6, 34, 34, 13, 3, 8, 1, 1, 61, 5, 2, 15, 18};
    int k = 77;
    Solution obj;
    cout << "Fulfilled capacity bags : " << obj.maximumBags(capacity, rocks, k);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    static bool cmp(vector<int> &a, vector<int> &b)
    {
        if (a[0] == b[0])
        {
            return a[1] < b[1];
        }
        else
        {
            return a[0] < b[0];
        }
    }

    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        int cnt = 0;
        sort(intervals.begin(), intervals.end(), cmp);

        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < n; i++)
        {
            if (intervals[i][0] >= end)
            {
                end = intervals[i][1];
            }
            else
            {
                cnt++;
                end = min(end, intervals[i][1]);
            }
        }

        return cnt;
    }
};

int main()
{
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    Solution obj;
    cout << " The minimum number of intervals you need to remove overlaps : " << obj.eraseOverlapIntervals(intervals) << endl;
    return 0;
}
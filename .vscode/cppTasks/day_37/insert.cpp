#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        for (auto &&i : intervals)
        {
            //  the new interval is after the range of other interval
            if (i[1] < newInterval[0])
                ans.push_back(i);
            // the new interval's range is before the other
            else if (newInterval[1] < i[0])
            {
                ans.push_back(newInterval);
                newInterval = i; // updating the new interval
            }
            // the new interval is in the range of the other interval
            else
            {
                newInterval[0] = min(newInterval[0], i[0]);
                newInterval[1] = max(newInterval[1], i[1]);
            }
        }
        // At the end after the loop just add the updated newIntervals
        ans.push_back(newInterval);
        return ans;
    }
};

int main()
{
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};
    Solution obj;
    vector<vector<int>> ans = obj.insert(intervals, newInterval);
    cout << "intervals after the insertion : ";
    cout << "{";
    for (auto x : ans)
    {
        cout << "{";
        for (auto y : x)
            cout
                << y << ",";
        cout << "},";
    }
    cout << "}";
    return 0;
}
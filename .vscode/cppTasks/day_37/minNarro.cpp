#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &points)
    {

        sort(points.begin(), points.end());
        int cnt = 1, k = INT_MIN;
        for (auto x : points)
        {
            if (k == INT_MIN)
            {
                k = x[1];
                continue;
            }
            if (x[0] <= k && k > x[1])
            {
                k = x[1];
                continue;
            }
            if (x[0] <= k)
                continue;
            else
            {
                cnt++;
                k = x[1];
            }
        }
        return cnt;

        // vector<pair<int,int>>arr;
        // arr.push_back({points[0][0],points[0][1]});
        // int cnt=1;
        // for(int i=1;i<points.size();i++){
        //     cout<<points[i][0]<<"_"<<points[i][1]<<", ";
        //     if(arr[arr.size()-1].second>=points[i][0]&& cnt>0){
        //         auto x=arr[arr.size()-1];

        //         int y=points[i][1]>=x.second?points[i][1]:x.second;

        //         pair<int,int> k={x.first,y};
        //         arr.pop_back();
        //         arr.push_back(k);
        //         cnt--;
        //         cout<<k.first<<" - "<<k.second<<"\n";
        //     }else{
        //         arr.push_back({points[i][0],points[i][1]});
        //         cnt++;
        //     }
        // }
        // return arr.size();
    }
};
int main()
{
    vector<vector<int>> points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    Solution obj;

    cout << "  minimum number of arrows that must be shot to burst all balloons. : " << obj.findMinArrowShots(points) << endl;

    return 0;
}
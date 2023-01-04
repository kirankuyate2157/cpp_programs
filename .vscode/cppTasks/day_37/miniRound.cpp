#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumRounds(vector<int> &tasks)
    {
        int n = tasks.size();
        if (n == 1 || n == 0)
            return -1;
        /*I approch */
        map<int, int> mp;
        int ans = 0;
        for (auto x : tasks)
            mp[x]++;
        for (auto cnt : mp)
        {
            if (cnt.second == 1)
                return -1;
            ans += cnt.second / 3;
            if (cnt.second % 3 != 0)
                ans++;
        }
        /*II approch */

        // for(int i=1;i<n;i++){
        //     cout<<tasks[i]<<" -- "<<tasks[i-1]<<" #"<<i<<"  = ";
        //     while( i<n &&(tasks[i-1]==tasks[i])){
        //         cnt++;
        //         i++;
        //     }
        //     cout<<cnt<<" -> ";
        //     if(cnt==1)return -1;
        //     if(cnt==2)ans++;
        //     cout<<ans<<" \n";
        //     if(cnt==4)ans+=cnt/2;
        //     if(cnt==3||cnt>4){
        //         ans+=cnt/3;
        //         cout<<"` "<<cnt/3<<" %"<<(cnt%3)<<"' ";
        //          cnt%=3;
        //         if(cnt>0&&cnt%2==0){
        //             cnt-=2;
        //             ans++;
        //         }
        //     }
        // cnt=1;
        // }
        return ans;
    }

    // to get the exponent of 5 and 2 in the number
    pair<int, int> getPair(int x)
    {
        int five = 0, two = 0;
        while (x % 5 == 0)
        {
            five++;
            x /= 5;
        }
        while (x % 2 == 0)
        {
            two++;
            x /= 2;
        }
        return {five, two};
    }
    int maxTrailingZeros(vector<vector<int>> &grid)
    {
        int r = grid.size(), c = grid[0].size(), ans = 0;
        vector<vector<pair<int, int>>> top(r, vector<pair<int, int>>(c, {0, 0})), left(r, vector<pair<int, int>>(c, {0, 0}));

        // top[i][j] will store sum of exponent of 5's and 2's from grid[0][j] to grid[i][j]

        cout << " Top \n";
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << getPair(grid[i][j]).first << " " << getPair(grid[i][j]).second << ", ";
                if (i == 0)
                    top[i][j] = getPair(grid[i][j]);
                else
                {
                    pair<int, int> p = getPair(grid[i][j]);
                    top[i][j].first = top[i - 1][j].first + p.first;
                    top[i][j].second = top[i - 1][j].second + p.second;
                }
                cout << "(" << top[i][j].first << "," << top[i][j].second << "), ";
            }
            cout << endl;
        }
        // left[i][j] will store sum of exponent of 5's and 2's from grid[i][0] to grid[i][j]

        cout << " Left \n";
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << getPair(grid[i][j]).first << " " << getPair(grid[i][j]).second << ", ";
                if (j == 0)
                    left[i][j] = getPair(grid[i][j]);
                else
                {
                    pair<int, int> p = getPair(grid[i][j]);
                    left[i][j].first = left[i][j - 1].first + p.first;
                    left[i][j].second = left[i][j - 1].second + p.second;
                }
                cout << "(" << left[i][j].first << " " << left[i][j].second << "), ";
            }
            cout << endl;
        }
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                pair<int, int> down, right;
                pair<int, int> curr = getPair(grid[i][j]);

                down.first = top[r - 1][j].first - top[i][j].first, down.second = top[r - 1][j].second - top[i][j].second;
                right.first = left[i][c - 1].first - left[i][j].first, right.second = left[i][c - 1].second - left[i][j].second;

                // four cases ---> (down,left), (down,right), (top,left), (top,right)
                ans = max(ans, min(down.first + left[i][j].first, down.second + left[i][j].second));
                ans = max(ans, min(down.first + right.first + curr.first, down.second + right.second + curr.second));
                ans = max(ans, min(top[i][j].first + left[i][j].first - curr.first, top[i][j].second + left[i][j].second - curr.second));
                ans = max(ans, min(top[i][j].first + right.first, top[i][j].second + right.second));
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> tasks = {2, 2, 3, 3, 2, 4, 4, 4, 4, 4};

    vector<vector<int>> grid = {{23, 17, 15, 3, 20},
                                {8, 1, 20, 27, 11},
                                {9, 4, 6, 2, 21},
                                {40, 9, 1, 10, 6},
                                {22, 7, 4, 5, 3}};

    Solution obj;
    cout << "Minimum rounds required to complete all the tasks : " << obj.minimumRounds(tasks) << "\n\n\n";
    cout << " \nmaximum number of trailing zeros in the product of a cornered path found in grid :\n  " << obj.maxTrailingZeros(grid);
    return 0;
}
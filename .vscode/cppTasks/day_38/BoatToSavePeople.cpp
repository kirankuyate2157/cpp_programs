#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        int n = people.size();
        sort(people.begin(), people.end());
        int i = 0, j = n - 1;
        int ans = 0;
        while (i <= j)
        {
            if (people[i] + people[j] <= limit)
            {
                i++;
            }
            j--;
            ans++;
        }
        return ans;
    }
};

int main()
{
    vector<int> people = {3, 2, 2, 1};
    int limit = 3;
    Solution obj;
    cout << "minimum number of boats to carry every : " << obj.numRescueBoats(people, limit) << endl;
    return 0;
}
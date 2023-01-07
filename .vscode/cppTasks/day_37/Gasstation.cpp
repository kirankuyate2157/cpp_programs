#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int gas_sum = 0, cost_sum = 0;
        gas_sum = accumulate(gas.begin(), gas.end(), gas_sum);
        cost_sum = accumulate(cost.begin(), cost.end(), cost_sum);
        // cout << cost_sum << " " << gas_sum << " ";
        if (gas_sum < cost_sum)
            return -1;

        int n = gas.size();
        int total = 0;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            total += (gas[i] - cost[i]);
            if (total < 0)
            {
                total = 0;
                ans = i + 1;
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> gas = {1, 2, 3, 4, 5}, cost = {3, 4, 5, 1, 2};
    Solution obj;
    cout << "the starting gas station's index if you can travel around the circuit once in the clockwise direction : " << obj.canCompleteCircuit(gas, cost) << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minStoneSum(vector<int> &piles, int k)
    {
        int sum = 0;
        priority_queue<int> pq;
        for (auto x : piles)
            pq.push(x);
        while (k--)
        {
            float x = (float)pq.top() / (float)2;
            pq.pop();
            pq.push(ceil(x));
        }
        while (!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};
int main()
{
    vector<int> piles = {4, 3, 6, 7};
    int k = 3;
    Solution obj;
    cout << "Minimum possible total number of stones remaining : " << obj.minStoneSum(piles, k);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<int>> dist(k + 2, vector<int>(n + 1, INT_MAX));

        for (int i = 0; i <= k + 1; i++)
            dist[i][src] = 0;
        for (int i = 1; i <= k + 1; i++)
        {
            for (auto x : flights)
            {
                int u = x[0];
                int v = x[1];
                int val = x[2];
                if (dist[i - 1][u] != INT_MAX)
                {
                    dist[i][v] = min(dist[i][v], dist[i - 1][u] + val);
                }
            }
        }
        if (dist[k + 1][dst] == INT_MAX)
            return -1;
        return dist[k + 1][dst];
    }
};
int main()
{

    int n = 4;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    int src = 0, dst = 3, k = 1;
    Solution obj;
    cout << "the cheapest flight price : " << obj.findCheapestPrice(n, flights, src, dst, k);
    return 0;
}
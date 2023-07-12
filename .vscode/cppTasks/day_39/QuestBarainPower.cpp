#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int n;
    long long giveme(int i, vector<vector<int>> &questions, vector<long long> &dp)
    {
        if (i >= n)
            return 0;
        if (dp[i] != -1)
            return dp[i];
        long long taken = questions[i][0] + giveme(i + questions[i][1] + 1, questions, dp);
        long long nottaken = giveme(i + 1, questions, dp);
        return dp[i] = max(nottaken, taken);
    }

    long long mostPoints(vector<vector<int>> &questions)
    {
        n = questions.size();
        vector<long long> dp(n + 1, -1);
        return giveme(0, questions, dp);
    }
};

int main()
{
    vector<vector<int>> questions = {{3, 2}, {4, 3}, {4, 4}, {2, 5}};
    Solution obj;
    cout << "maximum point by question : " << obj.mostPoints(questions) << endl;
    return 0;
}
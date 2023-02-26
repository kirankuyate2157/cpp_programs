#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {

        int n1 = word1.size();

        int n2 = word2.size();

        // declare a dp

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        // fill the table

        for (int i = 0; i <= n1; i++)
        {
            for (int j = 0; j <= n2; j++)
            {
                // if size of word1 is zero, then insert all the characters of word2 into word1

                // eg. word1 = "" and word2 = "abc"

                if (i == 0)
                    dp[i][j] = j;

                // if size of word2 is zero, then delete all the characters of word1

                // eg. word1 = "abc" and word2 = ""

                else if (j == 0)
                    dp[i][j] = i;

                else
                {
                    // if characters are same, we need zero operation

                    if (word1[i - 1] == word2[j - 1])
                    {
                        dp[i][j] = dp[i - 1][j - 1];
                    }

                    // if characters are not same, we can perform three operations i.e. insert, delete, replace

                    else
                    {
                        int insert = dp[i][j - 1];

                        int deletee = dp[i - 1][j];

                        int replace = dp[i - 1][j - 1];

                        dp[i][j] = 1 + min({insert, deletee, replace});
                    }
                }
            }
        }

        return dp[n1][n2];
    }
};

int main()
{

    string s1 = "hourse", s2 = "ros";
    Solution obj;
    cout << "minimum orpation are : " << obj.minDistance(s1, s2) << endl;

    return 0;
}
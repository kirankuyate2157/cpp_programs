#include <bits/stdc++.h>
using namespace std;
unordered_map<string, int> dp;
int cnt = 0;
int isSegment(string s, vector<string> sv)
{
    int n1 = s.size();
    int n2 = sv.size();
    if (n1 == 0)
        return 1;
    // if (dp[s] != 0)
    //     return dp[s];
    for (int i = 1; i <= n1; i++)
    {
        string sub = s.substr(0, i);
        int flg = 0;
        for (int j = 0; j < n2; j++)
        {
            if (sub.compare(sv[j]) == 0)
            {
                flg = 1;
                break;
            }
        }
        if (flg == 1 && isSegment(s.substr(i, n1 - i), sv) == 1)
        {
            cnt++;
            return  1;
        }
    }
    return -1;
}
int main()
{
    int n = 12;
    vector<string> B = {"i", "like", "sam", "sung", "samsung", "mobile", "ice", "cream", "icecream", "man", "go", "mango"};
    string A = "ilike";
    cout << isSegment(A, B)<<"\n";
    // for(auto x:dp){
    //     cout<<x.first<<" -> "<<x.second<<"\n";
    // }

    return 0;
}
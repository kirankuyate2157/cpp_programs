#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {

        vector<int> v1(26, 0), v2(26, 0);
        set<char> s1, s2;
        for (auto x : word1)
        {
            s1.insert(x);
            v1[x - 'a']++;
        }
        for (auto x : word2)
        {
            s2.insert(x);
            v2[x - 'a']++;
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        return v1 == v2 && s1 == s2;
    }
};

int main()
{ // close string or not
    string s1 = "cabbba", s2 = "abbccc";
    Solution obj;
    obj.closeStrings(s1, s2) ? cout << "yes both are so close." : cout << "not close.";
    return 0;
}
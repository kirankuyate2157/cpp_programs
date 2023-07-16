#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        map<char, int> mp;
        for (int i = 0; i < s.length(); i++)
        {
            mp[s[i]]++;
        }
        for (int i = 0; i < s.length(); i++)
        {
            mp[t[i]]--;
        }

        for (auto x : mp)
        {
            if (x.second != 0)
            {
                return false;
            }
        }
        return true;
    }
    bool isAnagram2(string s, string t)
    {
        if (s.length() != t.length())
            return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
int main()
{
    string s = "anagram", t = "nagaram";
    Solution obj;
    cout << " is an anagram : " << obj.isAnagram2(s, t);
    return 0;
}
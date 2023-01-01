#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {

        int m = pattern.length();
        vector<string> arr;
        istringstream ss(s);
        string word;
        while (ss >> word)
        {
            arr.push_back(word);
        }

        int n = arr.size();
        if (n != m)
            return false;
        bool flg = false;
        map<char, string> mp;
        map<string, char> mp2;
        for (int i = 0; i < n; i++)
        {
            if (mp.find(pattern[i]) != mp.end())
            {
                flg = true;
                if (mp[pattern[i]] != arr[i] || mp2[arr[i]] != pattern[i])
                    return false;
            }
            else
            {

                mp2[arr[i]] = pattern[i];
                mp[pattern[i]] = (arr[i]);
            }
        }
        if (!flg)
        {
            int i = 0;
            while (i < n)
            {
                if (mp.find(pattern[i]) != mp.end())
                {
                    if (mp[pattern[i]] != arr[i] || mp2[arr[i]] != pattern[i])
                        return false;
                }
                i++;
            }
        }

        return true;
    }
};
int main()
{
    /*Input: pattern = "abba", s = "dog cat cat fish"
      Output: false

      Input: pattern = "aaaa", s = "dog cat cat dog"
      Output: false
    */
    string p = "abba";
    string s = "dog cat cat dog";
    Solution obj;
    cout << "whether pattern is matching or not : " << obj.wordPattern(p, s);

    return 0;
}
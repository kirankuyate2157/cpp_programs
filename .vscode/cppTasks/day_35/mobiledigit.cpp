#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    vector<string> letterCombinations(string digits)
    {
        if (!digits.size())
        {
            return {};
        }

        vector<string> res;
        const vector<string> chars = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string temp;
        build(temp, 0, digits, chars, res);
        return res;
    }

    void build(string temp, int i, const string &digits, const vector<string> &chars, vector<string> &res)
    {
        if (i == digits.size())
        {
            res.push_back(temp);
            return;
        }

        int d = digits[i] - '0';

        for (char ch : chars[d])
            build(temp + ch, i + 1, digits, chars, res);
    }
};

int main()
{
    string digits = "23";
    Solution obj;
    vector<string> ans = obj.letterCombinations(digits);
    for (auto x : ans)
        cout << x << "  ";
    return 0;
}
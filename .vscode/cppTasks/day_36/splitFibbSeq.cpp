#include <bits/stdc++.h>
using namespace std;

#define ll long long
class Solution
{
public:
    vector<int> splitIntoFibonacci(string num)
    {
        vector<int> res;
        helper(num, res, 0);
        return res;
    }
    bool helper(string s, vector<int> &res, int p)
    {
        if (s.length() == p)
            return res.size() > 2;
        ll int n = 0;
        for (int i = p; i < s.length(); i++)
        {

            n = (n * 10) + (s[i] - '0');
            if (n > INT_MAX || n < INT_MIN || n < 0)
                return false;
            if (res.size() < 2 || (ll int)res[res.size() - 1] + (ll int)res[res.size() - 2] == n)
            {
                res.push_back(n);
                if (helper(s, res, i + 1))
                    return true;
                res.pop_back();
            }
            if (i == p && s[i] == '0')
                return false;
        }
        return false;
    }
};

int main()
{
    string s = "1101111";
    Solution obj;
    vector<int> res = obj.splitIntoFibonacci(s);
    for (auto x : res)
        cout << x << " ";
    if (res.size() > 0)
        cout << " \nyes ";
    else
        cout << "\n No";
    return 0;
}
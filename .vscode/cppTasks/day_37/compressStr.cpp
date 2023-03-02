#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int compress(vector<char> &chars)
    {
        unordered_map<string, int> mp;
        char prev = chars[0];
        int b = 0;
        for (char x : chars)
        {

            if (prev == x)
            {
                string k = to_string(b) + to_string(x);
                mp[k]++;
            }
            else
            {
                b++;
                string k = to_string(b) + to_string(x);
                mp[k]++;
            }
            prev = x;
        }
        vector<char> ans;
        set<string> st;
        prev = chars[0];
        b = 0;
        for (char x : chars)
        {
            string k = to_string(b) + to_string(x);
            if (x != prev)
            {
                b++;
                k = to_string(b) + to_string(x);
            }
            if (st.find(k) == st.end())
            {
                ans.push_back(x);
                if (mp[k] > 1)
                {
                    for (char o : to_string(mp[k]))
                        ans.push_back(o);
                }
                st.insert(k);
            }
            prev = x;
        }
        chars = ans;
        return ans.size();
    }
};
int main()
{

    vector<char> chars = {'a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b'};
    Solution obj;
    cout << "Solution : " << obj.compress(chars) << endl;
    for (char c : chars)
        cout << "," << c;
    return 0;
}
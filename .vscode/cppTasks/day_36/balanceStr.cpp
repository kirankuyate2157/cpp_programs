#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwaps(string s)
    {
        int n = s.length();
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < n; i++)
        {
            if (!st.empty() && st.top() == '[' && s[i] == ']')
                st.pop();
            else
                st.push(s[i]);
        }
        int cnt = st.size() / 2;
        if (cnt % 2 == 0)
            return cnt / 2;
        return (cnt + 1) / 2;
    }
};

int main()
{
    string s = "]]][[[";
    Solution obj;
    cout << "Minimum swap  are : " << obj.minSwaps(s);

    return 0;
}
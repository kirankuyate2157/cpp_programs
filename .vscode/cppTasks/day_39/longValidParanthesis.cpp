#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> st;
        st.push(-1);
        int maxlen = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                st.push(i);
            else
            {
                st.pop();

                if (st.empty())
                {
                    st.push(i);
                }
                else
                {
                    int len = i - st.top();
                    maxlen = max(len, maxlen);
                }
            }
        }
        return maxlen;
    }
};
int main()
{
    string s = "(()(()))";
    Solution obj;
    cout << "the long valid parathisis pair is : " << obj.longestValidParentheses(s);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        //     stack<long int> st ;
        //     for (string s : tokens) {
        //         if(s!="+"&&s!="-"&&s!="*"&&s!="/"){
        //             st.push(stoi(s));
        //         }
        //         else{
        //                 long  a=st.top();
        //                  st.pop();
        //                  long int b=st.top();
        //                  st.pop();
        //             if ("+"==s) st.push(a + b);
        //             else if ("-"==s) st.push(-a + b);
        //             else if ("/"==s) st.push((long int)( b / a));
        //             else if ("*"==s) st.push(a * b);
        //             }
        //     }

        //     return st.top();
        // }

        stack<long int> st;
        int n = tokens.size();
        cout << "(";
        for (int i = 0; i < n; i++)
        {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/")
            {
                st.push(stoi(tokens[i]));
            }
            else
            {

                long int a = st.top();
                st.pop();
                long int b = st.top();
                st.pop();
                long int ans = a + b;
                string x = tokens[i];
                cout << x << ",";
                if (x == "+")
                    ans = b + a;
                else if (x == "-")
                    ans = b - a;
                else if (x == "*")
                    ans = a * b;
                else if (x == "/")
                    ans = (long int)(b / a);
                else
                    return -1;

                st.push(ans);
            }
        }
        cout << ")  ";
        return st.top();
    }
};

int main()
{
    vector<string> arr = {"2", "1", "+", "3", "*"};
    Solution obj;
    cout << "ans is : " << obj.evalRPN(arr);

    return 0;
}
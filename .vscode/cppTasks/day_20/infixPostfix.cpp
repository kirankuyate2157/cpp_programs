#include <bits/stdc++.h>
using namespace std;
int preced(char x)     //applaying   BODMAS  rule... for oprator
{

    if (x == '^')
    {
        return 3;
    }
    else if (x == '/' || x == '*')
    {
        return 2;
    }
    else if (x == '+' || x == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

string InfixtoPostfix(string s)
{
    string res;              //result of postfix string ...
    stack<char> st;               //using stack..
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')      //checking opening bracketss...
        {
            st.push(s[i]);
            // continue;
        }
        else if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z')   //inserting  abretory  constant elemints from  given string 
        {
            res +=s[i];
        }

        else if (s[i] == ')')         //when closeing  bracket comes that time we will push all oprator from the stack until an unless opening bracket not comes..
        {
            while (!st.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && preced(st.top()) > preced(s[i]))      //pushing oprator by in result by bodmas rule....
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){            //again  by chance any element or charecter is reamining in stack they will be push into result string 
        res+=st.top();
        st.pop();
    } 
    return res;           //returning  postfix string 
}

int main()
{

string s="((a-b/c)*(a/x-l)/(a-b))";
string ans;
ans=InfixtoPostfix(s);
cout<<ans;
    return 0;
}
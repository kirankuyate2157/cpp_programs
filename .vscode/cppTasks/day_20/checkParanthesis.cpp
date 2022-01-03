#include <bits/stdc++.h>
using namespace std;

bool checkpar(string s)
{
    int n = s.length();
    stack<char> st;        //declaring stack of charercters
    char poped;
    for (int i = 0; i < n; i++)  // traversing the string 
    {

        if (s[i] == '{' || s[i] == '[' || s[i] == '(') //if any opening bracket there we can push into stack and then continue our process until and unless we not found the closing bracket....
        {
            st.push(s[i]);
            continue;
        }
        if (st.empty()) //if first baracket is closing then no need to check further this string is unbalaced so return false...
        {
            return false;
        }
        switch (s[i]) //if above all thing is clear then check where top opening bracked of stack is matching  with the current string  closeing bracket then pop and continue our process unti an unless string is all charecter of string is not visited...
        {
        case '}':
            poped = st.top();
            st.pop();
            if (poped == ')' || poped == ']')
            {
                return false;
            }
            break;
        case ')':
            poped = st.top();
            st.pop();
            if (poped == '}' || poped == ']')
            {
                return false;
            }
            break;
        case ']':
            poped = st.top();
            st.pop();
            if (poped == ')' || poped == '}')
            {
                return false;
            }
            break;
        }
    }
    return st.empty(); //string   is traversed and st and all thiung is happenned at the end stack is empty  and swatching case  have not poped(top) charecter it means some extra closing brackets or unordered bracked is going on so that time we return the  empty stack it return false
}

int main()
{
    string s = "{}()}";
    if (checkpar(s))
    {
        cout << "\n \t.....The string is balanced.....\n ";
    }
    else
    {
        cout << "\n  \t.....the string is Unbalanced.....\n";
    }
     return 0;
}
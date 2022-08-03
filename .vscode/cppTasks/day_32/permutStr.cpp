#include <bits/stdc++.h>
using namespace std;

void perm(string s, string ans)
{
    if (s.length() == 0)
    {
        cout << "_" << ans << endl;
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        string ros = s.substr(0, i) + s.substr(i + 1);
        // cout << ros << "+" << c << " ";
        perm(ros, ans + c);
    }
}

// if len==0 print answer
// loop i-len..len
//     ch=i
//     ros= sub0,i + sub i+1
//     per ros ,ans+ch,
int main()
{
    string s = "kiran";
    cout << s.substr(0) << endl;
    perm("ABC", "");

    return 0;
}
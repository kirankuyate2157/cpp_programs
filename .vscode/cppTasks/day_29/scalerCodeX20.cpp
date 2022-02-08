#include <bits/stdc++.h>
using namespace std;

void convrStr(string s)
{
    int n = s.length();
    cout<<"pass1";
    for (int i = 0; i< n; i++)
    {
        if ((s[i] <= 48))
        {
            if (s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/')
                cout << s[i];
            else
                cout << " not";
        }
    }
    // return 1;
    cout << "  end\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        convrStr(s);
    }

    return 0;
}
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        bool fg = true;
        for (int i = 0; i < s1.length(); i++)
        {
    
            if (s1[i] != s2[i] && (s1[i] != '?' && s2[i] != '?'))
            {
                fg = false;
                break;
            }
        }
        if (fg)
        {
            cout << "yes\n";
        }
        else
        {
            cout << "no\n";
        }
    }
    return 0;
}

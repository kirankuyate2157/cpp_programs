#include <bits/stdc++.h>
using namespace std;
bool check(char x)
{
    char vowels[] = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
    for (int i = 0; i < 10; i++)
    {
        if (x == vowels[i])
            return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1, T;
    cin >> T;
    while (t <= T)
    {
        string s;
        cin >> s;
        int n = s.length();
        int ans = 0;
        if (s[n - 1] != 'y')
        {
            if (check(s[n-1]))
                ans = 1;
            else
                ans = 2;
        }
        if (ans == 1)
        {
            cout << "Case #" << t << ": "<<s
                 << " is ruled by Alice. \n";
        }
        else if (ans == 2)
        {
            cout << "Case #" << t << ": "<<s
                 << " is ruled by Bob.\n";
        }
        else
        {
            cout << "Case #" << t << ": "<<s
                 << " is ruled by nobody.\n";
        }
        t++;
    }

    return 0;
}
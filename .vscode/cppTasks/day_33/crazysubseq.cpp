#include <bits/stdc++.h>
using namespace std;
#define ll long long
// CRASUB   <---- problem code
void show1(int n)
{
    while (n--)
        cout << "1";
}

int cntF1(string s, int a, int b)
{
    int cnt = 0;
    for (int i = a; i < b; i++)
        if (s[i] == '1')
            cnt++;
    return cnt;
}

int cntF0(string s, int x, int y)
{
    int cnt = 0;
    for (int i = x; i < y; i++)
        if (s[i] == '0')
            cnt++;
    return cnt;
}

void atZero(string s, int n)
{
    show1(cntF1(s, 0, n + 1));
    if (cntF0(s, 0, n + 1) % 2 == 1)
    {
        for (int j = n + 1; j < s.length() - 1; j++)
            cout << s[j];
    }
    else
    {
        int k = n;
        while (k >= 0 && s[k] != '0')
            k--;
        while (k >= 0 && s[k] == '0')
            k--;
        while (k >= 0 && s[k] != '0')
            k--;
        if (cntF0(s, 0, n + 1) == 0)
            for (int j = n + 1; j < s.length(); j++)
                cout << s[j];

        else if (k == -1)
            for (int j = n + 1; j < s.length() - 2; j++)
                cout << s[j];

        else
            for (int j = n + 1; j < s.length(); j++)
                cout << s[j];
    }
    cout << endl;
}

void atEven(string s, int n)
{

    int i = 0;
    int x = i;

    while (i < n && s[i] == '1')
        i++;
    x = i;
    while (i < n && s[i] == '0')
        i++;
    int y = i;
    while (i < n && s[i] == '1')
        i++;
    if (i == n)
    {
        show1(cntF1(s, 0, x));
        if (cntF1(s, y, n) <= 1)
        {
            cout << "00";
            show1(cntF1(s, y, n));
        }
        else if (cntF1(s, y, n) == 2)
        {
            cout << "0";
            show1(cntF1(s, y, n) - 1);
        }
        else
        {
            show1(cntF1(s, y, n) - 2);
        }
        cout << "\n";
    }
    else
    {
        show1(cntF1(s, 0, n));
        cout << "\n";
    }
}

void seeF1(string s)
{
    int i = s.length() - 1;
    int j = i;
    while (s[i] != '0')
        i--;
    while (s[j] == '0')
        j--;

    if (i > j)
    {
        show1(cntF1(s, 0, s.length()));
        cout << "0\n";
    }
    else if (j > i && s[j] != s[j - 1])
    {
        show1(cntF1(s, 0, s.length()) - 1);
        cout << "01\n";
    }
    else
    {
        show1(cntF1(s, 0, s.length()) - 1);
        cout << "\n";
    }
}

static void seeF3(string s)
{
    int i = s.length() - 1;
    int j = i;
    while (s[i] != '0')
        i--;
    while (s[j] == '0')
        j--;

    if (i > j)
    {
        show1(cntF1(s, 0, s.length()));
        cout << "0\n";
    }
    else if (j > i && s[j] != s[j - 1])
    {
        show1(cntF1(s, 0, s.length()) - 1);
        cout << "01\n";
    }
    else
    {
        show1(cntF1(s, 0, s.length()) - 1);
        cout << "\n";
    }
}

static void seeF2(string s, int cnt1, int cnt2)
{
    int i = s.length() - 1;
    int j = i;
    while (s[i] != '0')
        i--;
    while (s[j] == '0')
        j--;

    if (j > i && s[j] == s[j - 1])
    {
        show1(cntF1(s, 0, s.length()) - 1);
        cout << "\n";
    }
    else if (cnt1 > 1 && cnt2 > 1)
    {

        seeF3(s);
    }
    else
    {
        if (cnt1 == 1)
        {
            seeF3(s);
        }
        else
        {

            i = 0;
            while (s[i] != '0')
                i++;
            show1(cntF1(s, 0, i));
            if (cntF1(s, i, s.length()) > 1)
            {
                show1(cntF1(s, i, s.length()) - 1);
            }
            else
            {
                cout << "0";
                show1(cntF1(s, i, s.length()));
            }
            cout << "\n";
        }
    }
}

void atOdd(string s)
{
    int i = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    while (i < s.length() && s[i] != '0')
        i++;
    while (i < s.length() && s[i] == '0')
    {
        i++;
        cnt1++;
    }

    while (i < s.length() && s[i] != '0')
        i++;
    int x = i;
    while (i < s.length() && s[i] == '0')
    {
        i++;
        cnt2++;
    }
    while (i < s.length() && s[i] != '0')
        i++;
    if (x == s.length())
    {
        seeF1(s);
    }
    else if (i == s.length())
    {
        seeF2(s, cnt1, cnt2);
    }
    else
    {
        seeF3(s);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < s.length(); i++)
            if (s[i] == '0')
                cnt++;

        int zr = s.length() - 1;
        while (zr >= 0 && s[zr] == '0')
            zr--;

        if (cnt == 0 || cnt == s.length())
            cout << s << "\n";
        else if (s.length() - 1 - zr > 1)
            atZero(s, zr);
        else if (cnt % 2 != 0)
            atOdd(s);
        else
            atEven(s, s.length());
    }
    return 0;
}

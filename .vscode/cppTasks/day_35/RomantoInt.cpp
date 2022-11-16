#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s)
{
    int I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1000;
    int i = 0;
    int ans = 0;
    while (i < s.length())
    {
        if (s[i] == 'I' && (s[i + 1]) == 'V' || s[i + 1] == 'X'))
            {
                if (s[i + 1] == 'V')
                    ans += 4;
                else
                    ans += 9;
                i++;
            }
        else if (s[i] == 'X' && (s[i + 1]) == 'L' || s[i + 1] == 'C'))
            {
                if (s[i + 1] == 'L')
                    ans += 40;
                else
                    ans += 90;
                i++;
            }
        else if (s[i] == 'C' && (s[i + 1]) == 'D' || s[i + 1] == 'M'))
            {
                if (s[i + 1] == 'D')
                    ans += 400;
                else
                    ans += 900;
                i++;
            }
        else
        {
            if (s[i] == 'I')
                ans += 1;
            else if (s[i] == 'V')
                ans += V;
            else if (s[i] == 'X')
                ans += X;
            else if (s[i] == 'L')
                ans += L;
            else if (s[i] == 'C')
                ans += C;
            else if (s[i] == 'D')
                ans += D;
            else if (s[i] == 'M')
                ans += M;
        }
        i++;
    }
    return ans;
}

string intToRoman(int num)
{
    string ans = "";
    string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    string hrns[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    string ths[] = {"", "M", "MM", "MMM"};

    // cout << (num / 1000 )<< " + " << ((num % 1000) / 100) << " + " << ((num % 100) / 10)<< " + " << (num % 10);
    ans += ths[num / 1000] + hrns[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
    return ans;
}

string numberToWords(int num)
{

    string ans = "";
    string ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    string tens[] = {"", "Ten ", "Twenty ", "Thirty ", "Forty ", "Fifty ", "Sixty ", "Seventy ", "Eighty ", "Ninety "};
    string hrns[] = {"", "One Hundred ", "Two Hundred ", "Three Hundred ", "Four Hundred ", "Five Hundred ", "Six Hundred ", "Seven Hundred ", "Eight Hundred ", "Nine Hundred "};
    string ths[] = {"", "One Housand ", "Two Housand ", "Three Housand ", "Four Housand ", "Five Housand ", "Six Housand ", "Seven Housand ", "Eight Housand ", "Nine Housand "};
    string Mill[] = {"", "One Million ", "Two Million ", "Three Million ", "Four Million ", "Five Million ", "Six Million ", "Seven Million ", "Eight Million ", "Nine Million "};
    string Bill[] = {"", "One Billion ", "Two Billion ", "Three Billion ", "Four Billion ", "Five Billion ", "Six Billion ", "Seven Billion ", "Eight Billion ", "Nine Billion "};

    // cout << (num / 1000 )<< " + " << ((num % 1000) / 100) << " + " << ((num % 100) / 10)<< " + " << (num % 10);
    ans += Bill[num / 1000000000] + Mill[(num % 1000000000) / 1000000] + ths[num / 1000] + hrns[(num % 1000) / 100] + tens[(num % 100) / 10] + ones[num % 10];
    return ans;
}
vector<pair<int, string>> nums =
    {
        {1000000000, "Billion"}, {1000000, "Million"}, {1000, "Thousand"}, {100, "Hundred"}, {90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"}, {60, "Sixty"}, {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"}, {20, "Twenty"}, {19, "Nineteen"}, {18, "Eighteen"}, {17, "Seventeen"}, {16, "Sixteen"}, {15, "Fifteen"}, {14, "Fourteen"}, {13, "Thirteen"}, {12, "Twelve"}, {11, "Eleven"}, {10, "Ten"}, {9, "Nine"}, {8, "Eight"}, {7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"}};
string numberToWords(int num)
{
    if (num == 0)
        return "Zero";
    for (auto it = nums.begin();; ++it)
        if (num / it->first > 0)
            return (num >= 100 ? numberToWords(num / it->first) + " " : "") +
                   it->second + (num % it->first == 0 ? "" : " " + numberToWords(num % it->first));
}
int main()
{

    return 0;
}
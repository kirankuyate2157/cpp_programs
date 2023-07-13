#include <iostream>
#include <string>

using namespace std;

class Solution
{
public: // 465 case passed
    bool validPalindrome1(string s)
    {
        int l = 0, r = s.length() - 1;
        bool flg = true, k = false;
        while (l <= r)
        {
            if (s[l] != s[r])
            {
                if (s[l + 1] == s[r] && !k)
                {
                    l++;
                    k = true;
                }
                else if (s[l] == s[r - 1] && !k)
                {
                    r--;
                    k = true;
                }
                else
                {
                    flg = false;
                    break;
                }
            }
            l++, r--;
        }
        return flg;
    }
    // all case passed
    bool validPalindrome(string s)
    {
        int l = 0, r = s.length() - 1;
        int cnt = 0, cnt2 = 0;
        while (l <= r)
        {
            if (s[l] == s[r])
            {
                l++;
                r--;
            }
            else
            {
                cnt++;
                l++;
            }
            if (cnt > 1)
                break;
        }
        l = 0, r = s.length() - 1;
        while (l <= r)
        {
            if (s[l] == s[r])
            {
                l++;
                r--;
            }
            else
            {
                cnt2++;
                r--;
            }
            if (cnt2 > 1)
                break;
        }
        if (cnt == 1 || cnt2 == 1 || cnt == 0 || cnt2 == 0)
            return true;

        return false;
    }
};

int main()
{
    Solution solution;
    string input = "aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga";
    bool isPalindrome = solution.validPalindrome(input);
    if (isPalindrome)
    {
        cout << "The string is a palindrome after deleting at most one character." << endl;
    }
    else
    {
        cout << "The string is not a palindrome after deleting at most one character." << endl;
    }
    return 0;
}

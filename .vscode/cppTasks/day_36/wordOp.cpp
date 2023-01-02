#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string capitalizeTitle(string title)
    {
        vector<string> arr;
        string word;
        istringstream ss(title);
        while (ss >> word)
        {
            arr.push_back(word);
        }
        string ans = "";
        int k = 0;
        for (auto x : arr)
        {
            if (x.length() > 2)
            {
                for (int i = 0; i < x.length(); i++)
                {
                    if (i == 0)
                    {
                        x[i] = toupper(x[i]);
                    }
                    else
                    {
                        x[i] = tolower(x[i]);
                    }
                }
            }
            else
            {
                for (int i = 0; i < x.length(); i++)
                {
                    x[i] = tolower(x[i]);
                }
            }
            k++;
            ans += x;
            if (k != arr.size())
                ans += " ";
        }

        return ans;
    }
    bool detectCapitalUse(string word)
    {
        int n = word.length();
        int cnt = 0;
        int i = 0;
        for (; i < n; i++)
        {
            if (word[i] >= 'A' && word[i] <= 'Z')
            {
                cnt++;
            }
        }
        cout << i << " ";
        if ((cnt == 1 && word[0] >= 'A' && word[0] <= 'Z') || cnt == 0 || cnt == n)
            return true;
        return false;
    }
};

int main()
{
    string s = "INDIA";
    string title = "capiTalIze tHe titLe";
    Solution obj;
    cout << "check is valiad or not : " << obj.detectCapitalUse(s) << "\n";
    cout << "The beautifule tile is : " << obj.capitalizeTitle(title) << "\n";
    return 0;
}
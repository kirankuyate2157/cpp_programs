#include <bits/stdc++.h>
using namespace std;
bool areIsomorphic(string s1, string s2)
{  
    if (s1.length() != s2.length())
    {
        return false;
    }
    int i = 0, n = s1.length();
    unordered_map<char, char> freq;
    unordered_set<char> visited;
    while (i < n)
    {
        if (freq.find(s1[i]) == freq.end())
        {
            if (visited.find(s2[i]) != visited.end())
            {
                return false;
            }
            freq[s1[i]] = s2[i];
            visited.insert(s2[i]);
            if(freq[s1[i]] != s2[i])
            {
                return false;
            }
            i++;
        }
        return true;
    }
}

    int main()
    {
        string s1 = "aac";
        string s2 = "xxy";
     
        cout << areIsomorphic(s1, s2);
        return 0;
    }
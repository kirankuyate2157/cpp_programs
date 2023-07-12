#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> mpp(256, -1);

        int left = 0, right = 0;
        int n = s.size();
        int len = 0;
        while (right < n)
        {
            if (mpp[s[right]] != -1)
                left = max(mpp[s[right]] + 1, left); // \/
            //   directly jumping to the unique  index  abcaabcbb  reduiing the again aginne repete traver of leftpointers.. if reapeted case time the single timme is ok  one by one but multiple time when duplicates are max index than left the time we have to move left multiple position ahead... so ..

            mpp[s[right]] = right;

            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};
int main()
{
    string s = "abcaabcbb";
    Solution obj;
    cout << " max number is  : " << obj.lengthOfLongestSubstring(s);
    return 0;
}